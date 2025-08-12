#include <header.h>

int main(){
    // 端口IP
    char *ip = "192.168.106.130";
    char *port = "8080";

    // 创建socket
    int sofd = socket(AF_INET, SOCK_STREAM, 0);





    // 构建sockaddr
    struct sockaddr_in sockaddr;
    sockaddr.sin_addr.s_addr = inet_addr(ip);
    sockaddr.sin_port = htons(atoi(port));
    sockaddr.sin_family = AF_INET;
    // 绑定端口
    bind(sofd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));
    // 监听请求
    listen(sofd, 100);
    // 获取连接
    int netfd = accept(sofd, NULL, 0);

   int buflowat= 7;
   //设置接收缓冲区下限
   setsockopt(netfd,SOL_SOCKET,SO_RCVLOWAT,&buflowat,sizeof(int));

    printf(" brefore recv \n");
    char buf[60]={0};
    recv(netfd, buf, sizeof(buf), 0);
    printf("buf: %s \n", buf);

    bzero(buf, sizeof(buf));
    recv(netfd, buf, sizeof(buf), 0);
    printf("buf1: %s \n", buf);


    close(netfd);
    close(sofd);
    return 0;
}

