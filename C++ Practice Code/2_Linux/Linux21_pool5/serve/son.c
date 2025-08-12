#include "head.h"


// 子进程的逻辑
int son_main(int local_socket){

    while(1){
        // -> 1, 读取本地socket (recvmsg : local_socket[1])-> 等待父进程发任务过来
        int net_fd;
        local_recv(local_socket,  &net_fd);
        // -> 2, 和客户端通信

        // 和客户端进行交互
        do_worker(net_fd);

        // -> 3, 通知父进程, 客户端服务完毕
        close(net_fd);
        send(local_socket, "123", 3, 0);
    }
    return 0;
}


