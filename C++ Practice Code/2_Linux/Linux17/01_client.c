#include <header.h>

// 客户端
int main(){

    char *port = "8080";
    char *ip = "192.168.106.130"; 

    // socket函数执行:
    // -> 创建socket的通信端点对象(内核)
    // -> 端点对象的指针信息放入文件描述符数据
    // -> 返回给我们一个文件描述符数组的下标
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 构建目的主机的ip和端口
    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(port));
    sockaddr.sin_addr.s_addr=inet_addr(ip);

    // 发起三次握手
    int res_connect = connect(socket_fd, (struct sockaddr * )&sockaddr ,sizeof(sockaddr) );
    ERROR_CHECK(res_connect, -1, "connect123");

    //sleep(60);
    send(socket_fd, "hello", 5, 0);

    char buf[60] = {0};
    recv(socket_fd, buf, sizeof(buf), 0);
    printf("buf: %s \n", buf);

    close(socket_fd);
    return 0;
}

