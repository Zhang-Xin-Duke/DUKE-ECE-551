#include <header.h>

typedef struct conn{
    int net_fd; // 某个客户端链接的socket对象的文件描述符
    int alive; // 连接是否存在: 0正常连接,   非0代表连接断开
    time_t last_time;// 上一次说话的时间
}conn_t;

// 服务端
int main(){

    char *port = "8080";
    char *ip = "192.168.106.130";// 当前服务器所在的ip地址

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);


    // 如果某个端口处于time_wait状态, 
    // 我们可以通过如下的这个setsockopt函数, 设置socket重新使用处于time_wait端口
    int reuse = 1;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));


    struct sockaddr_in sockaddr;
    sockaddr.sin_family=AF_INET;// ipv4
    sockaddr.sin_port= htons(atoi(port));// 端口
    sockaddr.sin_addr.s_addr = inet_addr(ip); // ip地址
    int ret_bind = bind(socket_fd,  (struct sockaddr *)&sockaddr,   sizeof(sockaddr));
    ERROR_CHECK(ret_bind, -1, "bind");
    int ret_listen = listen(socket_fd, 10);
    ERROR_CHECK(ret_listen, -1, "listen");

    // 定义一个数组, 存储所有的客户端链接
    conn_t list[100];
    memset(list, 0, sizeof(list));
    int size=0; // 记录数组中记录的链接个数


    int epoll_fd = epoll_create(1);

    // 把用来三次握手的scoket对象放入监听
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = socket_fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, socket_fd, &event);

    while(1){

        struct epoll_event array[2];
        memset(array, 0, sizeof(array));

        int epoll_num = epoll_wait(epoll_fd, array, 2,  1000);


        for(int i=0; i<epoll_num; i++){
            int fd = array[i].data.fd;

            if(fd == socket_fd){
                // 新链接进来
                int net_fd = accept(socket_fd, NULL, NULL);
                // 存储到数组中
                list[size].net_fd = net_fd;
                list[size].alive = 0;
                time(&list[size].last_time);
                size++;

                // 把新获得的客户端链接, 也放入下一次监听
                event.data.fd = net_fd;
               epoll_ctl(epoll_fd, EPOLL_CTL_ADD, net_fd, &event); 
            }else{
                // 有人发送信息过来: fd
                // 读取信息 -> 转发
                char buf[60] = {0};
                int ret = recv(fd, buf, sizeof(buf), 0);
                if(ret == 0){
                    // 即可读, 有没有读到数据 -> 断开链接
                    // 关闭链接, 移除监听

                    for(int k=0; k<size; k++){
                        if(list[k].alive == 0 && list[k].net_fd == fd){
                            list[k].alive = 1;
                            break;
                        }
                    } 
                    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL);
                    close(fd);
                    continue;
                }

                // 读到数据转发
                for(int l=0; l<size; l++){
                    if(list[l].alive == 0 && list[l].net_fd != fd){
                        send(list[l].net_fd, buf, sizeof(buf), 0);
                    }else if(list[l].alive ==0 && list[l].net_fd == fd){
                        time(&list[l].last_time);
                    }
                }
            }

        }

        // for -> list -> 判断每一个是否超时
        for(int k=0; k<size; k++){
            time_t now_time;
            time(&now_time);

            if(list[k].alive==0 && now_time-list[k].last_time >=30){
                // 这个连接已经很久没说话了/30s, 踢掉
                // > 移除监听, 修改存活状态, 关闭链接
                epoll_ctl(epoll_fd, EPOLL_CTL_DEL, list[k].net_fd, NULL);
                list[k].alive =1;
                close(list[k].net_fd);
            }
        }
    }


    close(socket_fd);
    return 0;
}


