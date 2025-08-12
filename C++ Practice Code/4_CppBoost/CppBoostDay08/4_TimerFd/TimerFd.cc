#include "TimerFd.h"
#include <unistd.h>
#include <poll.h>
#include <sys/timerfd.h>

#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

TimerFd::TimerFd(TimerFdCallback &&cb, int initSec, int peridocSec)
: _tfd(createTimerFd())
, _cb(std::move(cb))
, _isStarted(false)
, _initSec(initSec)
, _peridocSec(peridocSec)
{

}

TimerFd::~TimerFd()
{
    close(_tfd);
}

//启动与停止
void TimerFd::start()
{
    struct pollfd pfd;
    pfd.fd = _tfd;//需要监听的文件描述符
    pfd.events = POLLIN;//监听的读事件

    //定时器启动
    setTimerFd(_initSec, _peridocSec);

    _isStarted = true;
    while(_isStarted)
    {
        int nready = poll(&pfd, 1, 5000);
        if(-1 == nready && errno == EINTR)
        {
            continue;
        }
        else if(-1 == nready)
        {
            cerr << "-1 == nready" << endl;
            return;
        }
        else if(0 == nready)
        {
            cout << ">>poll time_out!!!" << endl;
        }
        else
        {
            if(pfd.revents & POLLIN)
            {
                handleRead();
                if(_cb)
                {
                    _cb();
                }
            }
        }
    }
}
void TimerFd::stop()
{
    if(_isStarted)
    {
        _isStarted = false;
        setTimerFd(0, 0);//停止定时器
    }
}

//封装read
void TimerFd::handleRead()
{
    uint64_t one = 1;
    ssize_t ret = read(_tfd, &one, sizeof(uint64_t));
    if(ret != sizeof(uint64_t))
    {
        perror("handleRead");
        return;
    }
}

//封装TimerFd
int TimerFd::createTimerFd()
{
    int fd = timerfd_create(CLOCK_REALTIME, 0);
    if(fd < 0)
    {
        perror("createTimerFd");
        return -1;
    }
    return fd;
}

//设置定时器
void TimerFd::setTimerFd(int initSec, int peridocSec)
{
    struct itimerspec newValue;
    newValue.it_value.tv_sec = initSec;//起始时间
    newValue.it_value.tv_nsec = 0;

    newValue.it_interval.tv_sec = peridocSec;//时间间隔（周期时间）
    newValue.it_interval.tv_nsec = 0;

    int ret = timerfd_settime(_tfd, 0, &newValue, nullptr);
    if(ret < 0)
    {
        perror("setTimerFd");
        return;
    }
}
