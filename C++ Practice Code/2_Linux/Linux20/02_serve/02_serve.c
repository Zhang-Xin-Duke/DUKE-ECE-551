#include <header.h>

int main(){
    // 端口IP
    char *ip = "192.168.106.130";
    char *port = "8080";

    // 创建socket
    int sofd = socket(AF_INET, SOCK_STREAM, 0);

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

    while(1){
        
        // 读取文件名
        char file_name[60]= {0};
        recv(netfd, file_name, sizeof(file_name), 0);

        // 读取文件内容
        int file_fd = open(file_name, O_RDONLY);

        char buf[100]={0};
        int ret = read(file_fd, buf, sizeof(buf));

        // 发送文件内容给客户端
        send(netfd, buf, ret, 0);

        close(file_fd);
    }




    close(netfd);
    close(sofd);
    return 0;
}

