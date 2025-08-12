// http客户端
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/HttpUtil.h>
#include <signal.h>
#include <iostream>
using std::cout;
using std::cerr;
using std::string;
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    waitGroup.done();
    cout << "done\n";
}
void httpCallback(WFHttpTask *task){
	protocol::HttpRequest *req = task->get_req();//获取第一个模板参数，即请求
	protocol::HttpResponse *resp = task->get_resp(); //获取第二个模板参数，即响应
	int state = task->get_state(); //获取状态 成功还是失败
	int error = task->get_error(); //获取错误原因
	switch(state){
	case WFT_STATE_SYS_ERROR: //系统错误
		cerr <<"system error: " << strerror(error) << "\n";
		break;
	case WFT_STATE_DNS_ERROR: //网络错误
		cerr <<"DNS error: " << gai_strerror(error) << "\n";
		break;
	case WFT_STATE_SSL_ERROR:
		cerr <<"SSL error: " << error << "\n";
		break;
	case WFT_STATE_TASK_ERROR:
		cerr <<"Task error: "<< error << "\n";
		break;
	case WFT_STATE_SUCCESS: //正常状态
		break;
	}
	if (state != WFT_STATE_SUCCESS){
		cerr <<"Failed. Press Ctrl-C to exit.\n";
		return;
	}

	const void *body;
	size_t body_len;
	resp->get_parsed_body(&body, &body_len);
    string body_str = static_cast<const char *>(body);

	WFRedisTask * redisTask = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",10,nullptr);
	redisTask->get_req()->set_request("SET",{"taobao",body_str});
	series_of(task)->push_back(redisTask);
}
int main(){
    signal(SIGINT,sighandler);  
    WFHttpTask * httpTask = WFTaskFactory::create_http_task(
        "http://www.taobao.com",
        10, 
        10, 
        httpCallback //回调函数， 在将来，收到响应之后，框架会调用httpCallback，传入一个httpTask
    ); //创建任务
    httpTask->start(); //任务交给框架
    waitGroup.wait();
    cout << "finished!\n";
    return 0;
}