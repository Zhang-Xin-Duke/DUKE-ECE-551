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


    fd_set base_set;// 用来保存下一次循环用来监听谁
    FD_ZERO(&base_set);
    FD_SET(socket_fd, &base_set);
    
    int new_fd=0;

    while(1){

        fd_set set;
        FD_ZERO(&set);
        memcpy(&set, &base_set, sizeof(base_set));
        
        select(10, &set, NULL, NULL, NULL);

        if(FD_ISSET(socket_fd, &set)){
            // 此时此刻, 正在监听有没有新链接到了
            // 来了新链接

            // 获得新链接
            new_fd = accept(socket_fd, NULL, NULL);

            // 加入监听: 标准输入, 新链接
            FD_ZERO(&base_set);
            FD_SET(new_fd, &base_set);
            FD_SET(STDIN_FILENO, &base_set);

            continue;
        }

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
                // -> 重新监听用来三次握手的socket对象
                // -> 不再监听标准输入 和 旧的客户端通信的socket

                FD_ZERO(&base_set);
                FD_SET(socket_fd, &base_set);

                close(new_fd);
                continue;
            }
            printf("buf: %s \n", buf);
        }
    }


    close(new_fd);
    close(socket_fd);
    return 0;
}


