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

    // 和服务器交互
    while(1){
        // 客户端先向服务器发信息
        char buf[60] = {0};
        read(STDIN_FILENO, buf, sizeof(buf));
        send(socket_fd, buf, sizeof(buf), 0);
        
        // 读取服务器回复的信息
        memset(buf, 0, sizeof(buf));
        recv(socket_fd, buf, sizeof(buf), 0);
        printf("buf: %s \n", buf);
    }
    



    close(socket_fd);
    return 0;
}

