#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t capa)
: _capacity(capa)
, _que()
, _mutex()
, _notEmpty()
, _notFull()
{

}

TaskQueue::~TaskQueue()
{

}

//生产与消费
void TaskQueue::push(const int &value)
{
    //1、拿锁（上锁）
    /* _mutex.lock(); */
    unique_lock<mutex> ul(_mutex);
    //2、判断是不是满的
    /* if(full()) */
    while(full())
    {
        //3、如果是满的，就直接睡眠
        _notFull.wait(ul);
    }
    //4、如果不满，将数据value存起来
    _que.push(value);
    //5、唤醒消费者
    _notEmpty.notify_one();
    //6、解锁
    /* _mutex.unlock(); */
}

int TaskQueue::pop()
{
    unique_lock<mutex> ul(_mutex);

    while(empty())
    {
        _notEmpty.wait(ul);
    }

    //现获取第一个元素，然后删除
    int tmp = _que.front();
    _que.pop();

    _notFull.notify_one();

    return tmp;

}

//判空与判满
bool TaskQueue::empty() const
{
    return 0 == _que.size();
}

bool TaskQueue::full() const
{
    return _capacity == _que.size();
}
