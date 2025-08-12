
#include <signal.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>
#include <iostream>

using std::cout;
using std::cerr;
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    waitGroup.done();
}
int main(){
    signal(SIGINT,sighandler);

    WFHttpTask * httpTask = WFTaskFactory::create_http_task(
        "http://www.baidu.com",
        10,
        10,
        nullptr
    ); //创建一个http客户端任务

    httpTask->start(); //将任务交给框架
    httpTask->start(); 
    waitGroup.wait();
    cout << "finished!\n"; //不使用std::endl
}