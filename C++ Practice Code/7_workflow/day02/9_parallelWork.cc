#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/HttpUtil.h>
#include <workflow/Workflow.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::cerr;
using std::string;
using std::vector;
struct SeriesContext{
    string url;
    size_t body_len;
};
//定义一个全局变量
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    waitGroup.done();
}
void httpCallback(WFHttpTask *httpTask){
    protocol::HttpResponse *resp = httpTask->get_resp();
    const void *body;
	size_t body_len;
	resp->get_parsed_body(&body, &body_len);
    SeriesContext * context = static_cast<SeriesContext *>(series_of(httpTask)->get_context());
    context->body_len = body_len;
    cerr << "url = " << context->url << " "
         << "body_len = " << body_len << "\n";
}
void parallelCallback(const ParallelWork *parallelWork){
    string url;
    size_t body_len = 0;
    for(int i = 0; i < parallelWork->size(); ++i){
        SeriesContext * context = static_cast<SeriesContext *>(parallelWork->series_at(i)->get_context());
        if(body_len < context->body_len){
            url = context->url;
            body_len = context->body_len;
        }
        delete context;
    }
    cerr << "longest url = " << url << " body_len = " << body_len << "\n";
    WFRedisTask *redisTask = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",10,nullptr);
    redisTask->get_req()->set_request("SET",{url,std::to_string(body_len)});
    series_of(parallelWork)->push_back(redisTask);
}
int main(){ 
    signal(SIGINT,sighandler);
    //先创建一个空的并行任务
    ParallelWork * parallelWork = Workflow::create_parallel_work(parallelCallback);
    vector<string> urls = {"http://www.taobao.com","http://www.jd.com","http://www.baidu.com"};
    for(int i = 0; i < 3; ++i){
        //创建了http任务
        WFHttpTask * httpTask = WFTaskFactory::create_http_task(urls[i],10,10,httpCallback);
        //创建了小序列
        SeriesWork* series = Workflow::create_series_work(httpTask,nullptr);
        //申请context
        SeriesContext * context = new SeriesContext;
        series->set_context(context);
        context->url = urls[i];
        //将小序列加入到并行任务中
        parallelWork->add_series(series);
    }
    //执行并行任务
    parallelWork->start();
    waitGroup.wait();
    cout << "finished!\n"; //不使用std::endl
}