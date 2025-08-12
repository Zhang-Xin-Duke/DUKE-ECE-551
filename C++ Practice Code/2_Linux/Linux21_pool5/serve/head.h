#include <header.h>

enum{
    BUSY,
    FREE
};

// 定义一个结构体: 用来让父进程记录子进程一些信息
typedef struct son_s{
    pid_t pid;// 子进程的进程id
    int status;// 记录子进程的状态
    int local_socket; // 用来和这个子进程通信的本地socket的文件描述符
                
}son_t;

// 函数定义


// 初始化进程池: 启动子进程, 记录子进程启动信息
int init_pool(son_t *list, int num);

// 初始化tcp链接的socket对象
int init_socket(int *socket_fd, char *port, char *ip);

// 添加epoll监听
int add_epoll(int epoll_fd, int fd);

// 选取空闲子进程, 发送net_fd
int to_son(son_t *list, int num, int net_fd);

// 子进程的逻辑
int son_main(int local_socket);

// 把获得的新客户端socket交给某个子进程
int local_send(int local_socket, int net_fd);

int local_recv(int local_socket, int *net_fd);

// 和客户端进行通信的函数
int do_worker(int net_fd);
