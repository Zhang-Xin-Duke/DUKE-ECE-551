#include "head.h"


// 和客户端进行通信的函数
int do_worker(int net_fd){


    char *file_name = "1b.txt";

    // 发送文件名
    int file_name_len = strlen(file_name);
    send(net_fd, &file_name_len, sizeof(int), 0);
    send(net_fd, file_name, file_name_len , 0);

    int file_fd = open(file_name, O_RDONLY);

    // 给客户端文件大小
    struct stat st;
    fstat(file_fd, &st);
    //printf("size: %ld \n", st.st_size);
    send(net_fd, &st.st_size, sizeof(off_t), MSG_NOSIGNAL);


    // 发送文件内容


    // 循环读取文件: 循环发送读取的文件内容
    while(1){
        char buf[1000]={0};
        int ret = read(file_fd, buf, sizeof(buf));
        if(ret == 0){
            break;
        }
        send(net_fd, &ret, sizeof(int), 0);
        send(net_fd, buf, ret, 0);
        //sleep(1);
    }

    close(file_fd);

    return  0;
}


