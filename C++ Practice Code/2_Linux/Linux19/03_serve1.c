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

    char buf[20] = {0};
    int ret = recv(net_fd, buf, sizeof(buf), 0);
    printf("ret: %d \n", ret);
    ret = recv(net_fd, buf, sizeof(buf), 0);
    printf("ret2: %d \n", ret);
    ret = recv(net_fd, buf, sizeof(buf), 0);
    printf("ret3: %d \n", ret);
    ret = recv(net_fd, buf, sizeof(buf), 0);
    printf("ret4: %d \n", ret);
    ret = recv(net_fd, buf, sizeof(buf), 0);
    printf("ret5: %d \n", ret);

    ret = recv(net_fd, buf, sizeof(buf), 0);
    printf("ret6: %d \n", ret);

    close(socket_fd);
    return 0;
}

