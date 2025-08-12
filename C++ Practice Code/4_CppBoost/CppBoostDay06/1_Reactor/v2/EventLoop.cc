#include "EventLoop.h"
#include "Acceptor.h"
#include "TcpConnection.h"
#include <unistd.h>

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

EventLoop::EventLoop(Acceptor &acceptor)
: _epfd(createEpollFd())
, _evtList(1024)
, _isLooping(false)
, _acceptor(acceptor)
, _conns()
{
    //获取listenfd
    int listenfd = _acceptor.fd();
    //将listenfd放在红黑树上进行监听
    addEpollReadFd(listenfd);
}

EventLoop::~EventLoop()
{
    close(_epfd);
}

//事件是否在循环
void EventLoop::loop()
{
    _isLooping = true;
    while(_isLooping)
    {
        waitEpollFd();
    }
}

void EventLoop::unloop()
{
    _isLooping = false;
}

//为了封装epoll_wait函数
void EventLoop::waitEpollFd()
{
    int nready = 0;
    do{
        nready = epoll_wait(_epfd, &*_evtList.begin(), _evtList.size(), 3000);
    }while(-1 == nready && errno == EINTR);

    if(-1 == nready)
    {
        cerr << "-1 == nready" << endl;
        return;
    }
    else if(0 == nready)
    {
        cout << ">>epoll_wait timeout!!!" << endl;
    }
    else
    {
        //需要将vector手动扩容
        if(nready == (int)_evtList.size())
        {
            _evtList.resize(2 * nready);
        }

        for(int idx = 0; idx < nready; ++idx)
        {
            int fd = _evtList[idx].data.fd;
            int listenfd = _acceptor.fd();
            if(fd == listenfd)//listenfd就绪了
            {
                if(_evtList[idx].events & EPOLLIN)
                {
                    //处理新的连接请求
                    handleNewConnection();
                }
            }
            else
            {
                if(_evtList[idx].events & EPOLLIN)
                {
                    //老的连接上有数据发过来
                    handleMessage(fd);
                }
            }
        }
    }
}

//处理新的连接请求
void EventLoop::handleNewConnection()
{
    //只要accept函数有正确返回结果，就表明三次握手建立成功了
    int connfd = _acceptor.accept();
    if(connfd < 0)
    {
        perror("handleNewConnection");
        return;
    }

    //将connfd放在红黑树上进行监听
    addEpollReadFd(connfd);

    //就说明可以创建TcpConnection的对象
    TcpConnectionPtr con(new TcpConnection(connfd));

    //将键值对放在map中
    _conns.insert({connfd, con});
}

//处理老的连接上的数据额的收发
void EventLoop::handleMessage(int fd)
{
    auto it = _conns.find(fd);
    if(it != _conns.end())
    {
        //接收客户端的数据
        string msg = it->second->receive();
        cout << ">>recv msg from client: " << msg << endl;

        //将数据做处理之后，发送给客户端
        it->second->send("msg");
    }
    else
    {
        cout << "该连接不存在" << endl;
        return;
    }
}

//封装epoll_create函数
int EventLoop::createEpollFd()
{
    int fd = epoll_create(1);
    if(fd < 0)
    {
        perror("createEpollFd");
        return -1;
    }
    return fd;
}

//将文件描述符放在红黑树上进行监听
void EventLoop::addEpollReadFd(int fd)
{
    struct epoll_event evt;
    evt.data.fd = fd;
    evt.events = EPOLLIN;

    int ret = epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &evt);
    if(ret < 0)
    {
        perror("addEpollReadFd");
        return;
    }
}

//将文件描述符从红黑树上取消监听
void EventLoop::delEpollReadFd(int fd)
{
    struct epoll_event evt;
    evt.data.fd = fd;
    evt.events = EPOLLIN;

    int ret = epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, &evt);
    if(ret < 0)
    {
        perror("delEpollReadFd");
        return;
    }

}
