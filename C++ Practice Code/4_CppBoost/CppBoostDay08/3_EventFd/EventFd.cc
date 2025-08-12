#include "EventFd.h"
#include <unistd.h>
#include <poll.h>
#include <sys/eventfd.h>

#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

EventFd::EventFd(EventFdCallback &&cb)
: _efd(createEventFd())
, _cb(std::move(cb))
, _isStarted(false)
{

}

EventFd::~EventFd()
{
    close(_efd);
}

//启动与停止
void EventFd::start()
{
    struct pollfd pfd;
    pfd.fd = _efd;//需要监听的文件描述符
    pfd.events = POLLIN;//监听的读事件

    _isStarted = true;
    while(_isStarted)
    {
        int nready = poll(&pfd, 1, 3000);
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
void EventFd::stop()
{
    _isStarted = false;
}

//封装read
void EventFd::handleRead()
{
    uint64_t one = 1;
    ssize_t ret = read(_efd, &one, sizeof(uint64_t));
    if(ret != sizeof(uint64_t))
    {
        perror("handleRead");
        return;
    }
}

//封装write
void EventFd::wakeup()
{
    uint64_t one = 1;
    ssize_t ret = write(_efd, &one, sizeof(uint64_t));
    if(ret != sizeof(uint64_t))
    {
        perror("wakeup");
        return;
    }
}

//封装eventfd
int EventFd::createEventFd()
{
    int fd = eventfd(10, 0);
    if(fd < 0)
    {
        perror("createEventFd");
        return -1;
    }
    return fd;

}
