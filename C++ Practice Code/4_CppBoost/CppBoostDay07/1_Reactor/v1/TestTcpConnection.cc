#include "Acceptor.h"
#include "TcpConnection.h"
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;

void test()
{
    Acceptor acceptor("127.0.0.1", 8888);
    acceptor.ready();//此时处于监听状态

    //三次握手就已经建立，可以创建一条TCP连接
    TcpConnection con(acceptor.accept());

    //加调试,打印本端与对端的ip与端口号
    cout << con.toString() << " has connected" << endl;

    while(1)
    {
        /* string msg = con.receive(); */
        /* cout << ">>recv msg from client: "  << msg << endl; */
        /* con.send(msg); */
        cout << ">>recv msg from client: "  << con.receive() << endl;
        //向一个已经断开的进程执行两次写操作，会触发SIGPIPE信号，导致
        //程序奔溃（进程奔溃）
        con.send("hello baby\n");
    }
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

