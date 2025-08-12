#include "head.h"


// 和客户端进行通信的函数
int do_worker(int net_fd){


    char *file_name = "1.txt";
    int file_fd = open(file_name, O_RDONLY);

    char buf[100]={0};
    int ret = read(file_fd, buf, sizeof(buf));

    


    int file_name_len = strlen(file_name);
    send(net_fd, &file_name_len, sizeof(int), 0);
    send(net_fd, file_name, file_name_len , 0);


    send(net_fd, &ret, sizeof(int), 0);
    send(net_fd, buf, ret, 0);

    // 4个字节 5字节  4字节  9字节

    return  0;
}


