#include <header.h>
#include "queue.h"

typedef struct status_s{

    int num; // 子线程的个数
    pthread_t * thread_ids;// 线程的id

    queue_t queue;
    
    pthread_mutex_t lock;
    pthread_cond_t cond;

}status_t;

void *thread_main(void *p);

// 初始化共享的数据
int init_status(status_t * status, int num);

// 启动子线程
int init_thread(status_t *status);


// 启动socket监听
int init_socket(int *socket_fd, char *port, char *ip);

// 添加epoll监听
int add_epoll(int epoll_fd, int fd);

// 和客户端进行通信
int do_worker(int net_fd);
