#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;

int main(int argc, char *argv[])
{
    Producer pr;
    Consumer co;

    TaskQueue taskQue(10);

    //生产者线程，并且启动入口函数
    thread pro(&Producer::produce, &pr, std::ref(taskQue));
    
    //消费者线程，并且启动入口函数
    thread con(&Consumer::consume, &co, std::ref(taskQue));

    pro.join();
    con.join();

    return 0;
}

