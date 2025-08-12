#include <header.h>

// 使用epoll实现一个客户端和服务器基于tcp链接的聊天的程序
// 客户端
int main(){

    char *port="8080";
    char *ip="192.168.106.130";

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(port));
    sockaddr.sin_addr.s_addr = inet_addr(ip);
    connect(socket_fd, (struct sockaddr *)& sockaddr, sizeof(sockaddr));
    
    // epoll实现通信

    // 创建epoll对象:  包含监听和就绪集合
    int epoll_fd = epoll_create(1);

    // 放入监听: 标准输入,  socket_fd  

    // 标准输入, 放入监听: 监听是否可读
    struct epoll_event event; // 主要用来指明, 监听一个文件描述符的, 可读?可写?...
    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, STDIN_FILENO, &event);

    // socket_fd: 放入监听
    struct epoll_event event_socket;
    event_socket.events = EPOLLIN;
    event_socket.data.fd = socket_fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, socket_fd, &event_socket);

    int flag = 0;
    while(1){

        // 定义一个用来接收就绪的集合的数组
        struct epoll_event list[10];
        memset(list, 0, sizeof(list));

        // 监听
        int epoll_num = epoll_wait(epoll_fd, list, 10, -1);
        // epoll_num, 这个epoll返回值 有两种可能
        //    -> 1, 超时时间设为-1, 一直监听,  epoll_num就是拷贝到list中就绪的文件描述符的个数
        //    -> 2, 如果超时时间设置, epoll_num 是有可能等于0, 代表由于时间超时了,导致epoll_wait向下运行

        // 走到这: -1没有超时时间, 一定有就绪
        // 遍历就绪集合
        for(int i=0; i<epoll_num;i++ ){
            // 获得当前遍历次的, 就绪状态的文件描述符
            int fd = list[i].data.fd;

            if(fd == STDIN_FILENO){
                // 标准输入就绪
                char buf[60]={0};
                read(STDIN_FILENO, buf, sizeof(buf));
                send(socket_fd, buf, sizeof(buf), 0);
            }
            if(fd == socket_fd){
                // 对方给我发信息
                char buf[60]={0};
                int ret = recv(socket_fd, buf, sizeof(buf), 0);
                if(ret ==0){
                    printf("对方断开链接 \n");
                    flag=1;
                    break;
                }
                printf("buf: %s \n", buf);
            }
        }

        if(flag != 0){
            break;
        }
    }


    close(socket_fd);
    return 0;
}

