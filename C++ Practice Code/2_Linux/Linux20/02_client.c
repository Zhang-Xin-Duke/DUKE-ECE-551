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

    // stdin -> A.txt / B.txt 
    while(1){

        // 读取标准输入的问价 名 -> 发送服务器
        char file_name[60]={0};
        read(STDIN_FILENO, file_name, sizeof(file_name));
        file_name[strlen(file_name)-1] = 0;
        send(sofd, file_name, sizeof(file_name), 0);


        // 接收服务区回传的文件内容
        char buf[100] ={0};
        int ret = recv(sofd, buf, sizeof(buf), 0);

        //printf("buf: %s \n", buf);
        // write
        int file_fd = open(file_name, O_RDWR|O_CREAT, 0600);
        write(file_fd, buf, ret);

        close(file_fd);
    }


    close(sofd);
    return 0;
}

