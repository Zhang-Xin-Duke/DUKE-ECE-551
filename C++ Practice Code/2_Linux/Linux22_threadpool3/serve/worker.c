#include "head.h"


// 和客户端进行通信的函数
int do_worker(int net_fd){


    send(net_fd, "hello", 5, MSG_NOSIGNAL);

    return  0;
}


