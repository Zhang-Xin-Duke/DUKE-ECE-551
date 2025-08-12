#include "head.h"


// 和客户端进行通信的函数
int do_worker(int net_fd){


    char *file_name = "1b.txt";

    // 发送文件名
    int file_name_len = strlen(file_name);
    send(net_fd, &file_name_len, sizeof(int), 0);
    send(net_fd, file_name, file_name_len , 0);


    int file_fd = open(file_name, O_RDWR);

    // 获得文件大小
    struct stat st;
    fstat(file_fd, &st);
    send(net_fd, &st.st_size, sizeof(off_t), MSG_NOSIGNAL);

    // 发送文件内容
    // mmap: 映射
    // send
    void *p = mmap(NULL, st.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file_fd, 0 );

    send(net_fd, p, st.st_size, MSG_NOSIGNAL);

     munmap(p, st.st_size);

    close(file_fd);

    return  0;
}


