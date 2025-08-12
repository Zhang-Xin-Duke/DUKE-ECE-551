#include <header.h>

int main(){

    char *ip = "192.168.106.130";
    char *port = "8080";

    // 创建socket
    int sofd = socket(AF_INET, SOCK_STREAM, 0);
    // 构建sockaddr
    struct sockaddr_in  sockaddr;
    sockaddr.sin_addr.s_addr = inet_addr(ip);
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(port));
    // 建立socket连接
    connect(sofd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));

    send(sofd, "hellooo", 7, 0);
    sleep(10);
    printf("------ \n");
    send(sofd, "12345", 5, 0);

    close(sofd);
    return 0;
}

