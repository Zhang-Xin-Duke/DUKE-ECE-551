#include "head.h"

int pipe_fd[2];
void func(int num){
    write(pipe_fd[1], "1", 1);
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
                // 说明有信号过来
                // 通知子线程退出
                pthread_mutex_lock(&status.lock);
                status.exit_flag = 1;
                pthread_cond_broadcast(&status.cond);
                pthread_mutex_unlock(&status.lock);

                // 等待子线程都退出
                for(int x=0; x<4; x++){
                    pthread_join(status.thread_ids[x], NULL);
                }

                pthread_exit(NULL);
            }
        }
    }

    return 0;
}

