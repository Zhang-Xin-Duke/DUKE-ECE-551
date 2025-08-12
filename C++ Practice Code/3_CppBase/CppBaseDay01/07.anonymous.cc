#include <iostream>
using std::cout;
using std::endl;

//（1）匿名空间不要定义与全局空间中同名的实体；
//设计之初就要确定该内容要不要跨模块调用
//（2）匿名空间中的实体不能跨模块调用。
int val = 100;

namespace 
{
int val = 10;

void func(){
    cout << "func()" << endl;
}
}//end of anonymous namespace  


void test0(){
    /* cout << val << endl; */
    /* func(); */
    cout << ::val << endl;
    ::func();
}

int main(void){
    test0();
    return 0;
}
