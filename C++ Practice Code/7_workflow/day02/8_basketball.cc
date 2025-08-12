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
//自定义一个类型
struct SeriesContext{
	int number;
	string name;
};
//定义一个全局变量
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    waitGroup.done();
}
void CurryCallback(WFTimerTask *CurryTask){
	SeriesContext * context = static_cast<SeriesContext *>(series_of(CurryTask)->get_context());
	context->number = 30;
	context->name = "Curry";
	cerr << "I am Curry. I pass\n";
}
void JamesCallback(WFTimerTask *JamesTask){
	SeriesContext * context = static_cast<SeriesContext *>(series_of(JamesTask)->get_context());
	cerr << "I am James. I got ball from " << context->number << " " << context->name << ".I pass\n";
	context->number = 23;
	context->name = "James";
}
void KobeCallback(WFTimerTask *KobeTask){
	SeriesContext * context = static_cast<SeriesContext *>(series_of(KobeTask)->get_context());
	cerr << "I am Kobe. I got ball from " << context->number << " " << context->name << ".I shoot\n";
}
int main(){
    signal(SIGINT,sighandler);
	//创建任务和序列
	WFTimerTask * CurryTask = WFTaskFactory::create_timer_task(3,0,CurryCallback);
	WFTimerTask * JamesTask = WFTaskFactory::create_timer_task(3,0,JamesCallback);
	WFTimerTask * KobeTask = WFTaskFactory::create_timer_task(3,0,KobeCallback);
	SeriesWork * series = Workflow::create_series_work(CurryTask,nullptr);
	series->push_back(JamesTask);
	series->push_back(KobeTask);
	// series->set_callback([](const SeriesWork * series){
	// 	//const说明，在序列的回调执行的时候，不能添加新的任务了
	// 	SeriesContext * context = static_cast<SeriesContext *>(series->get_context());
	// 	delete context;
	// });

	//给context申请内存，放入序列中
	SeriesContext * context = new SeriesContext; //在堆上面去申请内存
	series->set_context(context);//将context存入series中
	series->set_callback([context](const SeriesWork * series){
		delete context;
	});
	series->start(); //启动序列
    waitGroup.wait();
    cout << "finished!\n"; //不使用std::endl
}