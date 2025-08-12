#include <header.h>

int main(){


    int local_socket[2];
    socketpair(AF_LOCAL, SOCK_STREAM, 0, local_socket);

    if(fork() == 0){
        //子进程
        
        close(local_socket[0]);


        struct msghdr msg;// 控制本地socket发送的数据
        memset(&msg, 0, sizeof(msg));

        // 正文信息
        char buf[60] = {0};
        struct iovec iov[1];
        iov[0].iov_base = buf;
        iov[0].iov_len = sizeof(buf);

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
        recvmsg(local_socket[1], &msg, 0);

        void *p =  CMSG_DATA(cms);
        int *fd = (int *)p;

        int file_fd = *fd;

        printf("son file_fd: %d \n", file_fd);

        write(file_fd, "nihao", 5);
    }else{
        close(local_socket[1]);
        int file_fd = open("1.txt", O_RDWR);

        struct msghdr msg;// 控制本地socket发送的数据
        memset(&msg, 0, sizeof(msg));

        // 正文信息
        char *str = "hello";
        struct iovec iov[1];
        iov[0].iov_base = str;
        iov[0].iov_len = strlen(str);

        msg.msg_iov = iov;
        msg.msg_iovlen =1;


        // 控制信息 
        struct cmsghdr *cms = (struct cmsghdr *) malloc( CMSG_LEN(sizeof(int)) );
        cms->cmsg_len = CMSG_LEN(sizeof(int));
        cms->cmsg_level = SOL_SOCKET;
        cms->cmsg_type = SCM_RIGHTS;

        void *p =  CMSG_DATA(cms);
        int *fd = (int *)p;
        *fd = file_fd;

        msg.msg_control = cms;
        msg.msg_controllen = CMSG_LEN(sizeof(int));

        printf("main file_fd: %d \n", file_fd);

        sendmsg(local_socket[0],  &msg,  0);
    }

    return 0;
}

