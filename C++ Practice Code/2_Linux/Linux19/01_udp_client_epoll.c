#include <header.h>

// 基于udp通信的客户端
int main(){

    char *port = "8080";
    char *ip = "192.168.106.130";

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(port));
    sockaddr.sin_addr.s_addr = inet_addr(ip);


    int epoll_fd = epoll_create(1);

    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, STDIN_FILENO, &event);

    event.data.fd=socket_fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, socket_fd, &event);

    while(1){
        // 保存/接收 epoll监听的就绪集合
        struct epoll_event list[2];
        memset(list, 0, sizeof(list));

        int epoll_num = epoll_wait(epoll_fd, list, 2, -1);

        // 
        for(int k=0; k<epoll_num; k++){
            int fd = list[k].data.fd;

            if(fd == STDIN_FILENO){
                // 说明监听的标准输入变得可读
                char buf[60]={0};
                read(STDIN_FILENO, buf, sizeof(buf));

                sendto(socket_fd, buf, sizeof(buf), 0, (struct sockaddr *)&sockaddr, sizeof(sockaddr));

            }
            if(fd == socket_fd){
                // socket对象变得可读, 说明服务器发信息给我
                char buf[60]={0};
                recvfrom(socket_fd, buf, sizeof(buf), 0, NULL, NULL);

                printf("buf: %s \n", buf);
            }
        }
    }


    close(socket_fd);
    return 0;
}

