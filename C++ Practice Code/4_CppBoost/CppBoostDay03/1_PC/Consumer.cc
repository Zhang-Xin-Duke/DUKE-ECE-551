#include "Consumer.h"
#include "TaskQueue.h"

#include <iostream>
#include <thread>

using std::cout;
using std::endl;


Consumer::Consumer()
{

}

Consumer::~Consumer()
{

}

//消费函数
void Consumer::consume(TaskQueue &taskQue)
{
    int cnt = 20;
    while(cnt--)
    {
        int tmp = taskQue.pop();
        cout << "<<Consumer consume = " << tmp << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
