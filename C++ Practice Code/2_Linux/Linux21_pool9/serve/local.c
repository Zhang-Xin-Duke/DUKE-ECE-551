#include "head.h"



// 把获得的新客户端socket交给某个子进程
int local_send(int local_socket, int net_fd, int flag){

    struct msghdr msg;// 控制本地socket发送的数据
    memset(&msg, 0, sizeof(msg));

    // 正文信息
    struct iovec iov[1];
    iov[0].iov_base = &flag;
    iov[0].iov_len = sizeof(int);

    msg.msg_iov = iov;
    msg.msg_iovlen =1;


    // 控制信息 
    struct cmsghdr *cms = (struct cmsghdr *) malloc( CMSG_LEN(sizeof(int)) );
    cms->cmsg_len = CMSG_LEN(sizeof(int));
    cms->cmsg_level = SOL_SOCKET;
    cms->cmsg_type = SCM_RIGHTS;

    void *p =  CMSG_DATA(cms);
    int *fd = (int *)p;
    *fd = net_fd;

    msg.msg_control = cms;
    msg.msg_controllen = CMSG_LEN(sizeof(int));


    sendmsg(local_socket,  &msg,  0);

    return 0;
}

int local_recv(int local_socket, int *net_fd, int *status){

    struct msghdr msg;// 控制本地socket发送的数据
    memset(&msg, 0, sizeof(msg));

    // 正文信息
    int *flag = (int *)malloc(sizeof(int));
    struct iovec iov[1];
    iov[0].iov_base = flag;
    iov[0].iov_len = sizeof(int);

    msg.msg_iov = iov;
    msg.msg_iovlen =1;


    // 控制信息 
    struct cmsghdr *cms = (struct cmsghdr *) malloc( CMSG_LEN(sizeof(int)) );
    cms->cmsg_len = CMSG_LEN(sizeof(int));
    cms->cmsg_level = SOL_SOCKET;
    cms->cmsg_type = SCM_RIGHTS;


    msg.msg_control = cms;
    msg.msg_controllen = CMSG_LEN(sizeof(int));

    // 接收数据: 从本地socket
    recvmsg(local_socket, &msg, 0);

    *status = *flag;

    void *p =  CMSG_DATA(cms);
    int *fd = (int *)p;

    *net_fd = *fd;

    return 0;
}







