#include <header.h>

// 基于udp通信的socket
int main(){

    char *port = "8080";
    char *ip = "192.168.106.130";

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(port));
    sockaddr.sin_addr.s_addr = inet_addr(ip);

    bind(socket_fd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));

    fd_set set;


    struct sockaddr_in sockaddr_client; // 接收客户端的ip地址和端口
    socklen_t len = sizeof(sockaddr_client);

    while(1){
        FD_ZERO(&set);
        FD_SET(STDIN_FILENO, &set);
        FD_SET(socket_fd, &set);

        select(socket_fd+1, &set, NULL, NULL, NULL);

        if(FD_ISSET(STDIN_FILENO, &set)){
            // 
            char buf[60]={0};
            read(STDIN_FILENO, buf, sizeof(buf));

            sendto(socket_fd, buf, sizeof(buf), 0,
                   (struct sockaddr *)&sockaddr_client, len);
        }
        if(FD_ISSET(socket_fd, &set)){
            char buf[60]={0};
            recvfrom(socket_fd, buf, sizeof(buf), 0,
                     (struct sockaddr *)&sockaddr_client, &len );

            printf("buf: %s \n", buf);
        }
    }

    close(socket_fd);
    return 0;
}

