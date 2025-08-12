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
void redisCallback2(WFRedisTask *redisTask){
	cerr << "callback 2 start\n";
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
    // 判断一下结果是string还是array
	if(val.is_string()){
		cerr << "value is string = " << val.string_value() << "\n";
	}
	else if(val.is_array()){
		cerr << "value is array\n";
		for(size_t i = 0; i < val.arr_size(); ++i){
			cerr << "i =  " << i << " value = " << val.arr_at(i).string_value() << "\n";
		}
	}
	cerr  << "callback 2 end\n";
}
void redisCallback1(WFRedisTask *redisTask){
	cerr << "callback 1 start\n";
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
    // 判断一下结果是string还是array
	if(val.is_string()){
		cerr << "value is string = " << val.string_value() << "\n";
	}
	else if(val.is_array()){
		cerr << "value is array\n";
		for(size_t i = 0; i < val.arr_size(); ++i){
			cerr << "i =  " << i << " value = " << val.arr_at(i).string_value() << "\n";
		}
	}
	cerr << "callback 1 end\n";
}

int main(){
    signal(SIGINT,sighandler);
    WFRedisTask * redisTask1 = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",10,redisCallback1);
	redisTask1->get_req()->set_request("SET",{"62test","How are you"});
    //redisTask1->start();//交给框架
	WFRedisTask * redisTask2 = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",10,redisCallback2);
	redisTask2->get_req()->set_request("GET",{"62test"});
    //redisTask2->start();//交给框架

	SeriesWork* series = Workflow::create_series_work(redisTask1,nullptr); //创建了一个序列
	series->push_back(redisTask2); //将任务2加入到序列中
	series->start();//将序列交给框架调度
    waitGroup.wait();
    cout << "finished!\n"; //不使用std::endl
}