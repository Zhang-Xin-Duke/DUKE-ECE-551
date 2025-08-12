#include <header.h>

// 服务端
int main(){

    char *port = "8080";
    char *ip = "192.168.106.130";// 当前服务器所在的ip地址

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sockaddr;
    sockaddr.sin_family=AF_INET;// ipv4
    sockaddr.sin_port= htons(atoi(port));// 端口
    sockaddr.sin_addr.s_addr = inet_addr(ip); // ip地址
    bind(socket_fd,  (struct sockaddr *)&sockaddr,   sizeof(sockaddr));
    listen(socket_fd, 10);
    int new_fd = accept(socket_fd, NULL, NULL);

    // 和客户端进行交互
    while(1){
        // 先读取客户端发过来的数据
        char buf[60] = {0};
        recv(new_fd, buf, sizeof(buf), 0);
        printf("buf: %s \n", buf);

        //读取标准输入回复给客户端
        memset(buf, 0, sizeof(buf));
        read(STDIN_FILENO, buf, sizeof(buf));
        send(new_fd, buf, sizeof(buf), 0);
    }


    close(new_fd);
    close(socket_fd);
    return 0;
}


