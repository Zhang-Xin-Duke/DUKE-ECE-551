#include "Computer3.hh"
#include <iostream>
using std::cout;
using std::endl;

extern void test1();

void test0(){
    Computer pc;
    pc.setBrand("Huawei");
    pc.setPrice(15000);
    pc.print();
}

int main(void){
    test0();
    test1();
    return 0;
}
