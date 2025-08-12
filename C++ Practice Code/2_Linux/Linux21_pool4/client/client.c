#include <header.h>

int main(){

    char *ip = "192.168.106.130";
    char *port = "8080";
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(atoi(port));
    connect(socketfd, (struct sockaddr *)&addr, sizeof(addr));


    // 读取文件名
    int file_name_len=0;
    recv(socketfd, &file_name_len, sizeof(int), 0);
    char file_name[60]={0};
    recv(socketfd, file_name, file_name_len, 0);

    int file_fd = open(file_name, O_RDWR|O_CREAT, 0600);

    // 读取文件内容
    while(1){
        int buf_len=0;
        int ret = recv(socketfd, &buf_len, sizeof(int), MSG_WAITALL);
        if(ret == 0){
            break;
        }
        if(buf_len != 1000){
            printf("buf_len: %d \n", buf_len);
        }
        char buf[1000]={0};
        ret = recv(socketfd, buf, buf_len, MSG_WAITALL);
        if(ret == 0){
            break;
        }


        write(file_fd, buf, buf_len);
    }



    close(file_fd);

    close(socketfd);
    return 0;
}

