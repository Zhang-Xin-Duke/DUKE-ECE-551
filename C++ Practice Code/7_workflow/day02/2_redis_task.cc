#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/HttpUtil.h>
#include <signal.h>
#include <iostream>
using std::cout;
using std::cerr;
//定义一个全局变量
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    waitGroup.done();
}
int main(){
    signal(SIGINT,sighandler);
    WFRedisTask * redisTask = WFTaskFactory::create_redis_task(
        "redis://127.0.0.1:6379",10,nullptr
    );//创建任务
    //设置请求 redis的指令
    protocol::RedisRequest *req = redisTask->get_req();
    req->set_request("SET",{"62test","world"});
    redisTask->start();//交给框架
    waitGroup.wait();
    cout << "finished!\n"; //不使用std::endl
}