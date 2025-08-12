#include <header.h>

int main(){

    if(fork() == 0){

        int fd = open("1.txt", O_RDWR);
        write(fd, "456", 3);
    }else{

        int fd = open("1.txt", O_RDWR);
        write(fd, "123", 3);

    }

    return 0;
}

