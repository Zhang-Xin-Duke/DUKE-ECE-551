#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/HttpUtil.h>
#include <workflow/Workflow.h>
#include <workflow/WFHttpServer.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::cerr;
using std::string;
using std::vector;
using std::cout;
using std::cerr;
//定义一个全局变量
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    waitGroup.done();
}
void process(WFHttpTask *serverTask){//设计一个process
    //cout << "process\n";
}
int main(){
    signal(SIGINT,sighandler);
    WFHttpServer server(process);//根据process创建了一个server对象
    if(server.start(1234) == 0){
        waitGroup.wait();
        cout << "finished!\n"; //不使用std::endl
        server.stop();
    }
    else{
        perror("server start");
        return -1;
    }
    
}