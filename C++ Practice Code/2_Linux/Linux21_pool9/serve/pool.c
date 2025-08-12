#include "head.h"


// 初始化进程池: 启动子进程, 记录子进程启动信息
int init_pool(son_t *list, int num){

    for(int i=0; i<num; i++){

        // 本地socket
        int local_socket[2];
        socketpair(AF_LOCAL, SOCK_STREAM, 0, local_socket);

        pid_t pid = fork();
        if(pid == 0){
            setpgid(0, 0);
            close(local_socket[0]);
            // 子进程

            son_main(local_socket[1]);

        }else{
            close(local_socket[1]);
            // 父进程
            list[i].pid = pid;
            list[i].status = FREE;
            list[i].local_socket = local_socket[0];
        }

    }

    return 0;
}


// 选取空闲子进程, 发送net_fd
int to_son(son_t *list, int num, int net_fd){

    for(int i=0; i<num; i++){
        if(list[i].status == FREE){
            // 把新获得的socket对象, 交给这个子进程
            //    -> 通过本地socket: list[i].local_socket: sendmsg
            local_send(list[i].local_socket, net_fd, 0);
            
            list[i].status=BUSY;
            break;
        }
    }

    return 0;
}

