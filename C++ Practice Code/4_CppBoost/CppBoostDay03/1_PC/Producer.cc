#include "Producer.h"
#include "TaskQueue.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;

Producer::Producer()
{

}

Producer::~Producer()
{

}

//生产者进行生产的函数
void Producer::produce(TaskQueue &taskQue)
{
    //种随机种子
    //n + shift + k 可以对于系统的函数进行手册查询
    ::srand(::clock());
    
    int cnt = 20;
    while(cnt--)
    {
        int number = ::rand() % 100;//产生随机数
        taskQue.push(number);
        cout << ">>Producer produce = " << number << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
