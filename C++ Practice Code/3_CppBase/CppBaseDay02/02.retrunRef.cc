#include <iostream>
using std::cout;
using std::endl;

int gNum = 100;

int func1(){
    return gNum;//发生复制
}

//可以简单理解为
//函数需要返回gNum本身时
//可以将函数返回值设为引用
int & func2(){
    return gNum;//不会发生复制
}

void test0(){
    //func1返回值是gNum的副本
    //属于临时变量，不能取地址
    /* &func1(); */
    
    //func2返回值是一个匿名的绑定gNum的引用
    //对这个引用取地址得到的就是gNum的地址
    cout << &gNum << endl;
    cout << &func2() << endl;
    ++func2();
    cout << gNum << endl;

    cout << func1() << endl;
    cout << func2() << endl;
}

int main(void){
    test0();
    return 0;
}
