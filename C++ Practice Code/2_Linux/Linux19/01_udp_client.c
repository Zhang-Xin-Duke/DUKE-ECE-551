#include <header.h>

// 基于udp通信的客户端
int main(){

    char *port = "8080";
    char *ip = "192.168.106.130";

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(port));
    sockaddr.sin_addr.s_addr = inet_addr(ip);

    fd_set set;

    while(1){
        FD_ZERO(&set);
        // 监听标准输入,  socket对象
        FD_SET(STDIN_FILENO, &set);
        FD_SET(socket_fd, &set);

        select(socket_fd+1, &set, NULL, NULL, NULL);
        
        if(FD_ISSET(STDIN_FILENO, &set)){
            // 说明监听的标准输入变得可读
            char buf[60]={0};
            read(STDIN_FILENO, buf, sizeof(buf));

            sendto(socket_fd, buf, sizeof(buf), 0, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
        }
        if(FD_ISSET(socket_fd, &set)){
            // socket对象变得可读, 说明服务器发信息给我
            char buf[60]={0};
            recvfrom(socket_fd, buf, sizeof(buf), 0, NULL, NULL);

            printf("buf: %s \n", buf);
        }

    }
    

    close(socket_fd);
    return 0;
}

