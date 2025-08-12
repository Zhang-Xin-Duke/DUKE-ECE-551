#include <header.h>

int main(){

    char *port = "8080";
    char *ip = "192.168.106.130";

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(port));
    sockaddr.sin_addr.s_addr = inet_addr(ip);
    bind(socket_fd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));

    listen(socket_fd, 10);

    int net_fd1 = accept(socket_fd, NULL, NULL);
    int net_fd2 = accept(socket_fd, NULL, NULL);

    fd_set set;
    while(1){
        FD_ZERO(&set);
        FD_SET(net_fd1, &set);
        FD_SET(net_fd2, &set);

        select(net_fd2+1, &set, NULL, NULL, NULL);

        if(FD_ISSET(net_fd1, &set)){
            char buf[60] = {0};
            int ret = recv(net_fd1, buf, sizeof(buf), 0);
            if(ret == 0){
                break;
            }
            send(net_fd2, buf, sizeof(buf), 0);
        }
        if(FD_ISSET(net_fd2, &set)){
            char buf[60] = {0};
            int ret = recv(net_fd2, buf, sizeof(buf), 0);
            if(ret == 0){
                break;
            }
            send(net_fd1, buf, sizeof(buf), 0);
        }
    }

    close(net_fd1);
    close(net_fd2);
    close(socket_fd);
    return 0;
}

