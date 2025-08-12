#include "multiply.hh"
#include <iostream>
using std::cout;
using std::endl;

extern void test1();

void test0(){
    cout << multiply(1.4,1.4) << endl;
}

int main(void){
    test0();
    test1();
    return 0;
}
