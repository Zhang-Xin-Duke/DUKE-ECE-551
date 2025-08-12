#include <header.h>

int main(){

    int fd = open("1.txt", O_RDWR);

    write(fd, "hello", 5);


    if(fork() == 0){

        write(fd, "456", 3);
    }else{

        write(fd, "123", 3);

    }

    return 0;
}

