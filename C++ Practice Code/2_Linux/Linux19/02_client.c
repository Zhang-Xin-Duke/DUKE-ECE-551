#include <header.h>

// 客户端
int main(){

    char *port = "8080";
    char *ip = "192.168.106.130"; 

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(port));
    sockaddr.sin_addr.s_addr=inet_addr(ip);
    int res_connect = connect(socket_fd, (struct sockaddr * )&sockaddr ,sizeof(sockaddr) );
    ERROR_CHECK(res_connect, -1, "connect123");

    // 使用select改造

    fd_set set;
    while(1){

        // 每次都需要重置监听集合
        FD_ZERO(&set);
        // 标准输入    和对方通信的socket对象
        FD_SET(STDIN_FILENO, &set);
        FD_SET(socket_fd, &set);

        select(10, &set, NULL, NULL, NULL);

        if(FD_ISSET(STDIN_FILENO, &set)){
            // 客户端先向服务器发信息
            char buf[60] = {0};
            read(STDIN_FILENO, buf, sizeof(buf));
            send(socket_fd, buf, sizeof(buf), 0);

        }
        if(FD_ISSET(socket_fd, &set)){
            // 读取服务器回复的信息
            char buf[60] = {0};
            ssize_t ret = recv(socket_fd, buf, sizeof(buf), 0);
            if(ret == 0){
                printf("对方断开链接 \n");

                // 

                break;
            }
            printf("buf: %s \n", buf);

        }

    }

    close(socket_fd);
    return 0;
}

