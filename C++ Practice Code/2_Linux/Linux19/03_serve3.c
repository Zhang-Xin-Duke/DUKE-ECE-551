#include <header.h>

// 服务端
int main(){

    char *port = "8080";
    char *ip = "192.168.106.130"; 

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(port));
    sockaddr.sin_addr.s_addr=inet_addr(ip);
    bind(socket_fd, (struct sockaddr *) &sockaddr, sizeof(sockaddr));

    listen(socket_fd, 10);

    int net_fd = accept(socket_fd, NULL, NULL);


    int epoll_fd = epoll_create(1);

    struct epoll_event event;
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = net_fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, net_fd, &event);

    while(1){
        struct epoll_event list[2];
        memset(list, 0, sizeof(list));

        printf(" ------ \n");
        int epoll_num = epoll_wait(epoll_fd, list, 2, -1);
        printf(" ******* \n");

        for(int i=0; i<epoll_num; i++){
            int fd = list[i].data.fd;

            char buf[20] = {0};
            int ret = recv(net_fd, buf, sizeof(buf), 0);
            printf("ret: %d \n", ret);

        }

        sleep(10);
    }

    close(socket_fd);
    return 0;
}

