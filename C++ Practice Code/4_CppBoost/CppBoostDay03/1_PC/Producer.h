#ifndef __PRODUCER_H__
#define __PRODUCER_H__

/* #include "TaskQueue.h" */
class TaskQueue;//前向声明

class Producer
{
public:
    Producer();
    ~Producer();

    //生产者进行生产的函数
    void produce(TaskQueue &taskQue);

private:

};

#endif
