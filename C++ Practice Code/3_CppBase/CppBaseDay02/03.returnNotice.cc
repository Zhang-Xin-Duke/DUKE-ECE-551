#include <iostream>
using std::cout;
using std::endl;

//不要返回一个局部变量的引用
//函数返回值为引用时，引用所绑定的变量本体的
//生命周期应该比函数更长
int & func(){
    /* int num = 100; */
    static int num = 100;
    return num;
}

//不要轻易地返回一个堆上变量的引用
//除非设计了完善的回收
int & func2(){
    int * p = new int(20);
    return *p;
}

void test0(){
    cout << func() << endl;
    /* cout << func2() << endl; */
    /* cout << &func2() << endl; */
    /* delete &func2(); */
    int & ref = func2();
    cout << ref << endl;
    delete &ref;
}

int main(void){
    test0();
    return 0;
}
