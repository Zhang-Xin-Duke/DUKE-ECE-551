#include <iostream>

using std::cout;
using std::endl;

int func1()
{
    cout << "int func1()" << endl;
    return 10;
}

int func2()
{
    cout << "int func2()" << endl;
    return 20;
}

int add(int x, int y)
{
    cout << "int add(int, int)" << endl;
    return x + y;
}

void test()
{
    typedef int A;
    //1、函数指针的定义方法
    /* typedef int(*)() pFunc; //error,这个语法不支持*/
    typedef int (*pFunc)();//函数指针类型的定义,C语言中取别名的方法
    /* using pFunc = int(*)();//C++11中的取别名的用法 */

    //2、函数指针与回调函数之间的关系（注册 + 执行）
    //3、了解：延迟调用的思想
    pFunc f = &func1;//回调函数注册
    cout << "===============" << endl;
    cout << "f() = " <<f() << endl;//回调函数进行了执行

    f = func2;
    cout << "f() = " <<f() << endl;

    /* f = add;//error，二者类型不匹配 */

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

