#include "EventFd.h"
#include <unistd.h>
#include <iostream>
#include <functional>
#include <thread>

using std::cout;
using std::endl;
using std::bind;
using std::thread;

class MyTask
{
public:
    void process()
    {
        cout << "MyTask is running!!!" << endl;
    }
};

void test()
{
    MyTask task;
    EventFd efd(bind(&MyTask::process, &task));
    thread th(&EventFd::start, &efd);//th是子线程，并且是A线程，那么主线程就应该是B线程
                //可以让主线程唤醒子线程

    int cnt = 10;
    while(cnt--)
    {
        efd.wakeup();
        sleep(1);
    }
    efd.stop();
    th.join();
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

