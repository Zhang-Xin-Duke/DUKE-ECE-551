#include <header.h>

void func(int  num){
    sleep(10);
}
int main(){
    signal(2, func);

    while(1);
    return 0;
}

