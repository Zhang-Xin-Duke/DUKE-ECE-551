#include <header.h>

int main(){

    char *port = "8080";
    char *ip = "192.168.106.130";

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);


    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(port));
    sockaddr.sin_addr.s_addr = inet_addr(ip);

    connect(socket_fd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));

    fd_set set;

    while(1){
        FD_ZERO(&set);
        FD_SET(STDIN_FILENO, &set);
        FD_SET(socket_fd, &set);

        select(socket_fd+1,&set, NULL, NULL, NULL );

        if(FD_ISSET(STDIN_FILENO, &set)){
            // 标准输入可读
            char buf[60] = {0};
            read(STDIN_FILENO, buf, sizeof(buf));
            send(socket_fd, buf, sizeof(buf), 0);
        }
        if(FD_ISSET(socket_fd, &set)){
            // socket对象变得可读 -> 对方发数据过来

            char buf[60] = {0};
            int ret = recv(socket_fd, buf, sizeof(buf), 0);
            if(ret == 0){
                printf("断开链接\n");
                break;
            }
            printf("buf: %s \n", buf);
        }
    }

    close(socket_fd);
    return 0;
}

