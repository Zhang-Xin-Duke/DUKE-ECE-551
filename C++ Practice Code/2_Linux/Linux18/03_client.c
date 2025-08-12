#include <header.h>

int main(){


    char *file_name="1.txt";

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi("8080"));
    sockaddr.sin_addr.s_addr = inet_addr("192.168.106.130");
    connect(socket_fd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));


    // 读取文件内容 -> 给服务器发送文件名, 发送文件内容

    int file_fd = open(file_name, O_RDONLY);
    char buf[100] = {0};
    int size = read(file_fd, buf, sizeof(buf));



    int file_name_len = strlen(file_name);
    send(socket_fd, &file_name_len, sizeof(int), 0);
    send(socket_fd, file_name, file_name_len, 0);
    
    send(socket_fd, &size, sizeof(size), 0);
    send(socket_fd, buf, size, 0);


    close(socket_fd);
    close(file_fd);
    return 0;
}

