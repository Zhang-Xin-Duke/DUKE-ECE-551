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
//定义一个全局变量
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    waitGroup.done();
}
void timerCallback(WFTimerTask* timerTask){
	time_t now = time(nullptr);
	cerr << "callback now = " << ctime(&now);
	WFTimerTask * nextTask = WFTaskFactory::create_timer_task(3,0,timerCallback);
	series_of(timerTask)->push_back(nextTask);
}
int main(){
    signal(SIGINT,sighandler);

	time_t now = time(nullptr);
	cerr << "now = " << ctime(&now);
	WFTimerTask * timerTask = WFTaskFactory::create_timer_task(3,0,timerCallback);
	timerTask->start();
    waitGroup.wait();
    cout << "finished!\n"; //不使用std::endl
}