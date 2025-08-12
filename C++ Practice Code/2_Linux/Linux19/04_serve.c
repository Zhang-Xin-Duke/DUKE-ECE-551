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
    printf("before accept\n");
    int net_fd = accept(socket_fd, NULL, NULL);

    printf("before recv\n");

    while(1){

        char buf[20] = {0};
        int ret = recv(net_fd, buf, sizeof(buf), MSG_DONTWAIT);
        printf("ret: %d \n", ret);

    }

    close(socket_fd);
    return 0;
}

