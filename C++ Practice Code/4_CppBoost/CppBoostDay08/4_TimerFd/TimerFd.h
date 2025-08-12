#ifndef __TIMERFd_H__
#define __TIMERFd_H__

#include <functional>

using std::function;

class TimerFd
{
    using TimerFdCallback = function<void()>;
public:
    TimerFd(TimerFdCallback &&cb, int initSec, int peridocSec);
    ~TimerFd();

    //启动与停止
    void start();
    void stop();

    //封装read
    void handleRead();

    //封装TimerFd
    int createTimerFd();

    //设置定时器
    void setTimerFd(int initSec, int peridocSec);

private:
    int _tfd;//timerfd_create创建的文件描述符
    TimerFdCallback _cb;//被唤醒后需要执行的任务
    bool _isStarted;//标识是否循环的标志
    int _initSec;//定时器的起始时间
    int _peridocSec;//定时器的时间间隔（周期性的时间）


};

#endif
