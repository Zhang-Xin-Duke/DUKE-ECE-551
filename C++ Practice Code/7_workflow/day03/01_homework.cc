#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/HttpUtil.h>
#include <workflow/Workflow.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::cerr;
//定义一个全局变量
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    waitGroup.done();
}

void redisCallback1(WFRedisTask *redisTask){
	cerr << "callback start\n";
	sleep(3);
    protocol::RedisRequest *req = redisTask->get_req();
	protocol::RedisResponse *resp = redisTask->get_resp();
	int state = redisTask->get_state();
	int error = redisTask->get_error();
    // val用来保存redis执行的结果
	protocol::RedisValue val;
    switch (state){
	case WFT_STATE_SYS_ERROR:
		cerr <<"system error: " << strerror(error) << "\n";
		break;
	case WFT_STATE_DNS_ERROR:
		cerr <<"DNS error: "  << gai_strerror(error) << "\n";
		break;
	case WFT_STATE_SSL_ERROR:
		cerr <<"SSL error\n";
		break;
	case WFT_STATE_TASK_ERROR:
		cerr <<"Task error\n";
		break;
	case WFT_STATE_SUCCESS:
    	resp->get_result(val);// 将redis的执行结果保存起来
		if (val.is_error()){
		   cerr <<  "Error reply. Need a password?\n";
		   state = WFT_STATE_TASK_ERROR;
		}
		break;
	}
	if (state != WFT_STATE_SUCCESS){
		cerr <<  "Failed. Press Ctrl-C to exit.\n";
		return;
	}
    
	cerr << "value is string = " << val.string_value() << "\n";
	if(val.is_string() && val.string_value() != "100"){
		//创建任务
		WFRedisTask * redisTask2 = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",10,redisCallback1);
		redisTask2->get_req()->set_request("GET",{val.string_value()}); //设置任务的指令
		SeriesWork * series = series_of(redisTask); //找到当前任务所在的序列
		series->push_back(redisTask2); //该序列正在运行中，只能往末尾添加任务
	}

	sleep(1);
	cerr << "callback end\n";
}

int main(){
    signal(SIGINT,sighandler);
    WFRedisTask * redisTask1 = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",10,redisCallback1);
	redisTask1->get_req()->set_request("GET",{"x1"});
	redisTask1->start(); 

    waitGroup.wait();
    cout << "finished!\n"; //不使用std::endl
}