#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

void print()
{
    cout << "print()" << endl;
}

void display()
{
    cout << "display()" << endl;
}

void test0(){
    atexit(print);
    atexit(print);
    atexit(display);
}

int main(void){
    test0();
    cout << "over" << endl;
    return 0;
}
