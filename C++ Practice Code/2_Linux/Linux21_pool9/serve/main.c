#include "head.h"

int pipe_fd[2];

void func(int num){
    //printf("2号信号 \n");
    write(pipe_fd[1], "2", 1);
}
int main(){

    pipe(pipe_fd);
    signal(2, func);

    // 启动池中进程: 去创建子进程
    // (父进程在创建子进程的同时, 需要记录: 子进程的忙闲状态, 和子进程单独通信的本地socket)
    son_t list[4];
    memset(list, 0, sizeof(list));
    init_pool(list, 4);


    // 监听端口
    int socket_fd;
    init_socket(&socket_fd, "8080", "192.168.106.130");


    // io多路复用:  听有没有新的链接进来, 子进程有没有发送信息过来(子进程干完活了)

    int epoll_fd = epoll_create(1);

    add_epoll(epoll_fd, socket_fd);

    for(int i=0; i<4; i++){
        add_epoll(epoll_fd, list[i].local_socket);
    }

    add_epoll(epoll_fd, pipe_fd[0]);
    while(1){

        struct epoll_event events[4];
        memset(events, 0, sizeof(events));
        int epoll_num = epoll_wait(epoll_fd, events, 4, -1);

        for(int i=0; i<epoll_num; i++){
            int fd = events[i].data.fd;

            if(fd == socket_fd){
                // 有新的链接进来:  accept取新连接 -> 交给空闲子进程
                int net_fd = accept(socket_fd, NULL, NULL);

                // 选取一个处于空闲状态的子进程, 把新的socket对象交给这个子进程
                to_son(list, 4, net_fd);

                close(net_fd);
            }else if(fd == pipe_fd[0]){
                // 有2号信号过来

                char buf[10]={0};
                read(pipe_fd[0], buf, sizeof(buf));
                printf("2号信号过来 \n");

                // 收到2号信号 -> 要求子进程退出
                // 通过本地socket给子进程要求子进程退出
                for(int k=0; k<4; k++){
                    local_send(list[k].local_socket, 0, -1);
                }

                // 给子进程收拾
                for(int k=0; k<4; k++){
                    wait( NULL );
                }
                
                // 走到这:  意味着四个子进程全部退出
                // TODO: 释放资源
                exit(0);

            }else {
                // 某个子进程给我发信息, 活干完了, 修改对这个子进程记录的忙闲状态

                char buf[60] ={0};
                recv(fd, buf, sizeof(buf), 0);

                for(int k=0; k<4; k++){
                    if(fd == list[k].local_socket){
                        list[k].status = FREE;
                        break;
                    }
                }

            }
        }

    }



    return 0;
}

