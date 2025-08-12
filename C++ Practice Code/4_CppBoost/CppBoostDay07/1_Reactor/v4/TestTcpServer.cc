#include "Acceptor.h"
#include "TcpConnection.h"
#include "EventLoop.h"
#include "TcpServer.h"
#include <unistd.h>
#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;

class MyTask
{
public:
    MyTask(const string &msg, const TcpConnectionPtr &con)
    : _msg(msg)
    , _con(con)
    {

    }
    void process()
    {
        //此处的_msg就是接收的客户端的数据，放在此处进行处理
        //也就是交给了线程池中的线程进行了处理
        _msg;
        //将接收过来客户端的数据在此处进行业务逻辑的处理
        //也就是decode、compute、encode
        //处理好之后的_msg是需要进行发送的，由谁发送处理好之后的数据呢？
        //肯定就只能是TcpConnection的对象，因为该类的对象具备send函数
        //也就是发送数据的能力
        //线程池中的线程在处理好业务逻辑时候，数据是由Reactor进行发送
        //的，而不是由线程池中的子线程在发送，所以此处应该是由线程池
        //中的线程将数据发送给Reactor把
        //sendInLoop函数的作用就是将处理好之后的数据发送到Reactor中
        //也就是EventLoop,然后由EventLoop/Reactor进行发送
        _con->sendInLoop(_msg);

        //线程池中的线程在处理好数据之后其实是可以直接发送数据给EventLoop
        //Reactor的，但是Reactor/EventLoop并没有阻塞等待线程池处理数据，
        //所以此时需要让线程池中的线程去通知EventLoop/Reactor接收数据
        //设计到新的问题：线程池与Reactor通信问题？两个线程的通信问题?
        //解决方案：现在提供了在线程或者进程之间进行通信的方式eventfd
        //
        //最终归结为两大点：
        //1、eventfd如何通信？
        //2、sendInLoop函数如何发送数据给EventLoop
    }
private:
    string _msg;
    TcpConnectionPtr _con;
};

//连接建立
void onNewConnection(const TcpConnectionPtr &con)
{
    cout << con->toString() << " has connected!!!" << endl;
}

//消息到达
void onMessage(const TcpConnectionPtr &con)
{
    string msg = con->receive();
    cout << ">>recv msg from client : " << msg << endl;

    MyTask task(msg, con);

    threadPool.addTask(bind(&MyTask::process, task))

    /* //处理客户端的数据 */
    /* con->send(msg); */
}

//连接断开
void onClose(const TcpConnectionPtr &con)
{
    cout << con->toString() << " has closed!!!" << endl;
}

void test()
{
    ThreadPool pool(4, 10);
    pool.start();

    TcpServer server("127.0.0.1", 8888);
    server.setAllCallback(std::move(onNewConnection)
                          , std::move(onMessage)
                          , std::move(onClose));
    server.start();
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

