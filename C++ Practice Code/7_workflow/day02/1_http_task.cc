// http客户端
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>
#include <workflow/HttpUtil.h>
#include <signal.h>
#include <iostream>
using std::cout;
using std::cerr;
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

	//展示了请求头
	cerr << req->get_method() << " "
		 << req->get_http_version() << " "
	     << req->get_request_uri() << "\n";// 方法 版本 路径和查询参数
	protocol::HttpHeaderCursor reqCursor(req); // cursor起到一个类似于迭代器的作用
	std::string name;
	std::string value;
	while (reqCursor.next(name, value)){//不停地取出下一个首部字段
        cerr << "name = " << name << " value = " << value << "\n";
    }

	//展示响应头
	cerr << resp->get_http_version() << " "
		 << resp->get_status_code()  << " "
		 << resp->get_reason_phrase() << "\n";//版本 状态码 原因字符串
	protocol::HttpHeaderCursor respCursor(resp);
	while (respCursor.next(name, value)){
        cerr << "name = " << name << " value = " << value << "\n";
    }
	
}
int main(){
    signal(SIGINT,sighandler);
   
    WFHttpTask * httpTask = WFTaskFactory::create_http_task(
        "http://www.baidu.com",
        10, 
        10, 
        httpCallback //回调函数， 在将来，收到响应之后，框架会调用httpCallback，传入一个httpTask
    ); //创建任务
    protocol::HttpRequest *req = httpTask->get_req();
	req->add_header_pair("Key1","Value1");
    httpTask->start(); //任务交给框架
    waitGroup.wait();
    cout << "finished!\n";
    return 0;
}