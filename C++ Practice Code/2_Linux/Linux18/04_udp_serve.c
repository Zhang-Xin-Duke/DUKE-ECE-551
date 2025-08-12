#include <header.h>

// 底层基于udp通信的socket的服务端
int main(){

    char *port="8080";
    char *ip="192.168.106.130";

    int socket_fd=socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in sockaddr;
    sockaddr.sin_family=AF_INET;
    sockaddr.sin_port=htons(atoi(port));
    sockaddr.sin_addr.s_addr=inet_addr(ip);
    bind(socket_fd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));



    char buf[60] = {0};

    //recvfrom: 除了读取数据从socket对象, 还可以获取这个数据来自于那个客户端的地址信息
    struct sockaddr_in sockaddr_client;
    socklen_t len = sizeof(sockaddr_client);

    recvfrom(socket_fd, buf, sizeof(buf), 0, (struct sockaddr *)&sockaddr_client, &len);
    printf("buf: %s \n", buf);

    sendto(socket_fd, "nihao", 5, 0,(struct sockaddr *)&sockaddr_client, sizeof(sockaddr_client) );



    close(socket_fd);
    return 0;
}

