#include <header.h>

// 基于udp通信的socket的客户端
int main(){

    char *port="8080";
    char *ip="192.168.106.130";

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    // 给服务器使用udp发送一个数据
    // 让服务器回复一份数据
    struct sockaddr_in sockaddr;
    sockaddr.sin_family=AF_INET;
    sockaddr.sin_port=htons(atoi(port));
    sockaddr.sin_addr.s_addr=inet_addr(ip);

    sendto(socket_fd, "hello", 5, 0, (struct sockaddr *)&sockaddr, sizeof(sockaddr));

    char buf[60]={0};
    recvfrom(socket_fd, buf, sizeof(buf), 0, NULL, NULL);
    printf("buf: %s \n", buf);

    close(socket_fd);
    return 0;
}

