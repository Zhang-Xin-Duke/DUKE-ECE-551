#ifndef __TASK_H__
#define __TASK_H__

class Task
{
public:
    Task();
    virtual ~Task();

    //如何执行任务的函数
    virtual void process() = 0;

private:

};

#endif
