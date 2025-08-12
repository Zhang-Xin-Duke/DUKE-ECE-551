#include "head.h"

int main(){

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
            }
        }


    }



    return 0;
}

