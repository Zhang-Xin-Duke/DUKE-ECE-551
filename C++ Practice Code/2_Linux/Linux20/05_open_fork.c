#include <header.h>

int main(){

    int pipe_fd[2];
    pipe(pipe_fd);

    if(fork() == 0){
        int fd = 0;
        read(pipe_fd[0], &fd, sizeof(int));
        printf("fd: %d \n", fd);

        int ret = write(fd, "hello", 5);
        ERROR_CHECK(ret , -1, "write");

        while(1);

    }else{
        // 父进程

        int file_fd = open("1.txt", O_RDWR);
        
        printf("f: file_fd: %d \n", file_fd);
        write(pipe_fd[1],  &file_fd, sizeof(int));

        while(1);
    }

    return 0;
}

