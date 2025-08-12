#include <header.h>

// 服务端
int main(){

    char *port = "8080";
    char *ip = "192.168.106.130";// 当前服务器所在的ip地址

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 设置端口, 开始监听
    struct sockaddr_in sockaddr;
    sockaddr.sin_family=AF_INET;// ipv4
    sockaddr.sin_port= htons(atoi(port));// 端口
    sockaddr.sin_addr.s_addr = inet_addr(ip); // ip地址
    // 参数1: 绑定那个socket对象
    // 参数2: 绑定的端口
    // 参数3: 结构体的长度
    bind(socket_fd,  (struct sockaddr *)&sockaddr,   sizeof(sockaddr));

    // 开始监听
    listen(socket_fd, 10);

    // 从全连接队列中， 取出一个已经三次握手完毕的连接
    // -》 获得一个专门为这个连接服务的socket对象
    int new_fd = accept(socket_fd, NULL, NULL);

    printf("-------- \n");
    char buf[60] = {0};
    recv(new_fd, buf, sizeof(buf), 0);
    printf("********* \n");
    printf("buf: %s \n", buf);

    send(new_fd, "nihao", 5, 0);



    close(new_fd);
    close(socket_fd);
    return 0;
}


