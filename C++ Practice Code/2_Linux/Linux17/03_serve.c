#include <header.h>

// 服务端
int main(){

    char *port = "8080";
    char *ip = "192.168.106.130";// 当前服务器所在的ip地址

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);


    // 如果某个端口处于time_wait状态, 
    // 我们可以通过如下的这个setsockopt函数, 设置socket重新使用处于time_wait端口
    int reuse = 1;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));


    struct sockaddr_in sockaddr;
    sockaddr.sin_family=AF_INET;// ipv4
    sockaddr.sin_port= htons(atoi(port));// 端口
    sockaddr.sin_addr.s_addr = inet_addr(ip); // ip地址
    int ret_bind = bind(socket_fd,  (struct sockaddr *)&sockaddr,   sizeof(sockaddr));
    ERROR_CHECK(ret_bind, -1, "bind");
    int ret_listen = listen(socket_fd, 10);
    ERROR_CHECK(ret_listen, -1, "listen");
    int new_fd = accept(socket_fd, NULL, NULL);

    fd_set set;

    while(1){
        FD_ZERO(&set);
        FD_SET(STDIN_FILENO, &set);
        FD_SET(new_fd, &set);

        select(10, &set, NULL, NULL, NULL);

        if(FD_ISSET(STDIN_FILENO, &set)){
            //读取标准输入回复给客户端
            char buf[60] = {0};
            read(STDIN_FILENO, buf, sizeof(buf));
            send(new_fd, buf, sizeof(buf), 0);
        }
        if(FD_ISSET(new_fd, &set)){
            // 先读取客户端发过来的数据
            char buf[60] = {0};
            int ret = recv(new_fd, buf, sizeof(buf), 0);
            if(ret == 0){
                // 走到这, 意味着select觉得new_fd可读
                // 真正读new_fd, 又没有读到任何数据, 而且recv没有阻塞
                // 说明对方断开链接
                printf("对方断开链接 \n");
                break;
            }
            printf("buf: %s \n", buf);
        }
    }


    close(new_fd);
    close(socket_fd);
    return 0;
}


