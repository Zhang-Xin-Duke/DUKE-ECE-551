#include "head.h"


void func(int num){
    printf("num: %d \n", num);
}
// 和客户端进行通信的函数
int do_worker(int net_fd){

    signal(13, func);

    char *file_name = "1b.txt";

    // 发送文件名
    int file_name_len = strlen(file_name);
    send(net_fd, &file_name_len, sizeof(int), 0);
    send(net_fd, file_name, file_name_len , 0);


    // 发送文件内容
    int file_fd = open(file_name, O_RDONLY);


    // 循环读取文件: 循环发送读取的文件内容
    while(1){
        char buf[1000]={0};
        int ret = read(file_fd, buf, sizeof(buf));
        if(ret == 0){
            break;
        }
        ret  = send(net_fd, &ret, sizeof(int), MSG_NOSIGNAL);
        printf("ret : %d \n", ret);
        if(ret == -1){
            break;
        }

        ret = send(net_fd, buf, ret, 0);
        printf("ret1 : %d \n", ret);
        if(ret == -1){
            break;
        }
        sleep(1);
    }

    close(file_fd);

    return  0;
}


