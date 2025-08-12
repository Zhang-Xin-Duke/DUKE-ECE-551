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


    fd_set base_set;// 用来保存下一次循环用来监听谁
    FD_ZERO(&base_set);
    FD_SET(socket_fd, &base_set);

    while(1){

        fd_set set;
        FD_ZERO(&set);
        memcpy(&set, &base_set, sizeof(base_set));
        
        struct timeval tv;
        tv.tv_sec =1;
        tv.tv_usec=0;
        select(10, &set, NULL, NULL, &tv);

        if(FD_ISSET(socket_fd, &set)){
            // 有新链接进来
            int net_fd = accept(socket_fd, NULL, NULL);

            // 存储到数组中
            list[size].net_fd = net_fd;
            list[size].alive = 0;
            time(&list[size].last_time);
            size++;

            // 把新获得的客户端链接, 也放入下一次监听
            FD_SET(net_fd, &base_set);
        }

        // 判断是否某个客户发信息了, 确认是那个客户端
        // 遍历所有的记录的客户端链接net_fd, 判断是否在set这个就绪集合中, 如果在-> 这个net_fd发信息过来
        for(int i=0; i<size; i++){

            if(list[i].alive==0 && FD_ISSET(list[i].net_fd, &set)){
                // 走到这: 说明 list[i].net_fd所代表的客户端, 是正常连接
                //        -> 并且, 这个连接在就绪集合中 -> 说明对方发送信息过来

                // 读取对方发的信息
                char buf[60] = {0};
                int recv_ret = recv(list[i].net_fd, buf, sizeof(buf), 0);

                if(recv_ret == 0){
                    // 读到数据个数为0, 并且可读 -> 说明对方关闭了链接
                    // 移除监听
                    FD_CLR(list[i].net_fd,  &base_set);
                    // 修改记录
                    list[i].alive = 1;
                    // 关闭链接
                    close(list[i].net_fd);
                    continue;
                }
                // 走到这: 说明对方确实发送数据过来
                //      -> 转发给所有人
                for(int j=0; j<size; j++){
                    if(list[j].alive==0 && list[j].net_fd != list[i].net_fd){
                        // 说明是一个正常连接, 并且不是我自己
                        send(list[j].net_fd, buf, sizeof(buf), 0);
                    }
                }

                time(&list[i].last_time);
            }

        }

        // 一万用户同时在线

        // for -> list -> 判断每一个是否超时
        for(int k=0; k<size; k++){
            time_t now_time;
            time(&now_time);

            if(list[k].alive==0 && now_time-list[k].last_time >=30){
                // 这个连接已经很久没说话了/30s, 踢掉
                // > 移除监听, 修改存活状态, 关闭链接
                FD_CLR(list[k].net_fd, &base_set);
                list[k].alive =1;
                close(list[k].net_fd);
            }
        }


    }


    close(socket_fd);
    return 0;
}


