#include "head.h"

int pipe_fd[2];
void func(int num){
    write(pipe_fd[1], "123", 3);    
}
int main(){
    pipe(pipe_fd);

    if(fork() != 0){
        // 父进程
        signal(2, func);

        wait(NULL);
        exit(0);
    }
    // 子进程
    setpgid(0, 0);



    // 初始化status_t结构体
    status_t status;
    init_status(&status, 4);

    // 启动子线程
    init_thread(&status);

    // 创建三次握手的socket
    int socket_fd;
    init_socket(&socket_fd, "8080", "192.168.106.130");

    int epoll_fd = epoll_create(1);

    add_epoll(epoll_fd, socket_fd);

    // 把管道的读端放入epoll监听
    add_epoll(epoll_fd, pipe_fd[0]);

    while(1){
        struct epoll_event events[2];
        memset(events, 0, sizeof(events));

        int epoll_num = epoll_wait(epoll_fd, events, 2, -1);

        // 遍历就绪集合
        for(int i=0; i<epoll_num; i++){
            int fd = events[i].data.fd;

            if(fd == socket_fd){
                // 新链接进来
                int net_fd = accept(socket_fd, NULL, NULL);

                pthread_mutex_lock(&status.lock);
                enQueue(&status.queue, net_fd);

                pthread_cond_broadcast(&status.cond);
                pthread_mutex_unlock(&status.lock);
            }else if(fd == pipe_fd[0]){
                // 说明管道可读 -> 父进程在写管道 -> 父进程收到信号才写管道
                // 走到: 说明父进程收到了信号
                char buf[60]={0};
                read(pipe_fd[0], buf, sizeof(buf));

                printf("信号过来 \n");
                // 子线程先退出: 子线程退出之后  再让主线程退出
                // pthread_cancel: 给四个子线程发送cancel请求, 要求子线程退出
                for(int x=0; x<4; x++){
                    pthread_cancel(status.thread_ids[x]);
                }
                // pthread_join: 在这, 用来捕捉子线程是否退出
                // 等待四个子线程退出
                for(int x=0; x<4; x++){
                    pthread_join( status.thread_ids[x], NULL);
                }
                 
                // 子线程都退出了, 主线程也退出
                pthread_exit(NULL);
            }
        }


    }



    return 0;
}

