#include <wfrest/HttpServer.h>
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
using std::map;
using std::pair;
//定义一个全局变量
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    waitGroup.done();
}
int main(){
    signal(SIGINT,sighandler);
    wfrest::HttpServer server;
    // GET /hello
    server.GET("/hello",[](const wfrest::HttpReq *req, wfrest::HttpResp * resp){
        cout << "hello\n";
        resp->append_output_body("hello"); //workflow基类
    });
    // POST /world
    server.POST("/world",[](const wfrest::HttpReq *req, wfrest::HttpResp * resp){
        resp->String("world");//wfrest派生类
    });

    server.GET("/login",[](const wfrest::HttpReq *req, wfrest::HttpResp * resp){
        resp->File("postform.html");
    });
    server.POST("/login",[](const wfrest::HttpReq *req, wfrest::HttpResp * resp){
        const map<string,string> & bodyMap = req->form_kv();
        for(auto it:bodyMap){
            cout << "first = " << it.first << " second = " << it.second << "\n";
        }
    });

    server.GET("/upload",[](const wfrest::HttpReq *req, wfrest::HttpResp * resp){
        resp->File("upload.html");
    });
    server.POST("/upload",[](const wfrest::HttpReq *req, wfrest::HttpResp * resp){
        map<string,pair<string,string>> & form = req->form();
        for(auto it:form){
            cout << "first =" << it.first
                 << "second.first = " << it.second.first
                 << "second.second = " << it.second.second << "\n";
        }
    });

    // login1?username=niqiu&password=123
    server.POST("/login1",[](const wfrest::HttpReq *req, wfrest::HttpResp * resp){
        //map<string,string> queryMap = req->query_list(); //触发拷贝
        //auto queryMap = req->query_list(); //触发拷贝
        const map<string,string> &queryMap = req->query_list();
        //auto & queryMap = req->query_list();
        for(auto it:queryMap){
            cout << "first = " << it.first << " second = " << it.second << "\n";
        }
    });


    server.POST("/login2",[](const wfrest::HttpReq *req, wfrest::HttpResp * resp, SeriesWork *series){
        map<string,string> queryMap = req->query_list();
        for(auto it:queryMap){
            cout << "first = " << it.first << " second = " << it.second << "\n";
        }
        WFRedisTask *redisTask = WFTaskFactory::create_redis_task("redis://127.0.0.1:6379",10,
            [queryMap,resp](WFRedisTask *redisTask){
                resp->String("success");
            }
        );
        string username = queryMap["username"];
        redisTask->get_req()->set_request("HGET",{"62user",username});
        series->push_back(redisTask);
    });
    if(server.track().start(1234) == 0){
        server.list_routes();
        waitGroup.wait();
        cout << "finished!\n"; //不使用std::endl
        server.stop();
    }
    else{
        perror("server start");
        return -1;
    }

}