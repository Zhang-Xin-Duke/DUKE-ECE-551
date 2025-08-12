#include <header.h>

void func(int num){

    printf("func1\n");
    sleep(20);
    printf("func2\n");
}

void func2(int num){

    printf("3号信号1\n");
    sleep(20);
    printf("3号信号2\n");
}
int main(){

    // 同类信号无法打断同类信号的执行
    // 不同同类信号可以打断当前信号的执行
    signal(2, func);
    //signal(3, func2);

    while(1);
    return 0;
}

