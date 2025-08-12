// WaitGroup 让某个线程处于等待状态
#include <workflow/WFFacilities.h>
// WFHttpServer.h 包含server类的设计
#include <workflow/WFHttpServer.h>
#include <iostream>
#include <string>
#include <signal.h>
#include <unistd.h>
using std::cout;
using std::string;
struct SeriesContext{
    string name;
    string password;
    protocol::HttpResponse *resp; // 决定了回复给客户端的内容
};
static WFFacilities::WaitGroup waitGroup(1);
void sigHandler(int signum){
    cout << "done!\n";
    waitGroup.done();
}
void redisCallback(WFRedisTask * redisTask){
    // 获取redis的执行结果
    protocol::RedisValue result;
    protocol::RedisResponse * resp = redisTask->get_resp();
    resp->get_result(result); //拿到redis的结果

    // 访问context
    SeriesContext * context =  static_cast<SeriesContext *>(series_of(redisTask)->get_context());
    if(result.is_string() && result.string_value() == context->password){ //传入的密码对比redis里面密码
        cout << context->name << " success\n";
        context->resp->append_output_body("<html>success</html>"); //修改响应的内容
    }else{
        cout << context->name << " fail\n";
        context->resp->append_output_body("<html>fail</html>");
    }
}
void process(WFHttpTask *serverTask){ //回复给客户端的响应 一定是serverTask的resp决定的
    protocol::HttpRequest *req = serverTask->get_req();
    string uri = req->get_request_uri();//获取用户的path和query
    cout << uri << "\n";
    // /login?username=niqiu&password=123
    string nameKV = uri.substr(0,uri.find("&"));
    string passwordKV = uri.substr(uri.find("&")+1);
    string name = nameKV.substr(nameKV.find("=")+1);
    string password = passwordKV.substr(passwordKV.find("=")+1); //解析，提取去传入的用户名和密码
    cout << "name = " << name << ", password = " << password << "\n";
    // 申请一片内存空间，用于序列内的任务共享数据
    SeriesContext * context = new SeriesContext;
    context->name = name;
    context->password = password;
    context->resp = serverTask->get_resp();
    series_of(serverTask)->set_context(context); //将 用户名、密码、响应的地址 存入context中
    // 创建一个redis任务
    WFRedisTask * redisTask = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",10,redisCallback);
    // hget 62user niqiu
    redisTask->get_req()->set_request("HGET",{"62user",name});//需要一个redis任务，才能构造出响应来
    series_of(serverTask)->push_back(redisTask);
}
int main(){
    signal(SIGINT,sigHandler);
    WFHttpServer server(process);
    if(server.start(12345) == 0){
        waitGroup.wait();
        server.stop();
    }
    else{
        perror("server start failed!");
        return -1;
    }
    cout << "finished!\n"; 
    return 0;
}