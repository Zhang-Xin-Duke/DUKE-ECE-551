#include <iostream>
#include <functional>
#include <string>

using std::cout;
using std::endl;
using std::bind;
using std::function;
using std::string;

int add(int x, int y)
{
    cout << "int add(int, int)" << endl;
    return x + y;
}

int multiply(int x, int y, int z)
{
    cout << "int multiply(int, int, int)" << endl;
    return x * y * z;
}

class Example
{
public:
    //非静态的成员函数的第一个参数的位置隐含this指针
    //    Example *  this
    int add(int x, int y)
    {
        cout << "int Example::add(int, int)" << endl;
        return x + y;
    }
};

void test()
{
    //add的形态（类型、标签）
    //什么是函数类型？函数的返回类型 + 函数列表（参数个数、顺序、类型）
    //add的原始类型：int(int, int)
    //bind改变了函数的形态.
    //f的类型int()
    /* auto f = bind(&add, 1, 2); */
    //因为function存储的函数类型，也将function称为函数的容器
    function<int()> f = bind(&add, 1, 2);
    cout << "f() = " << f() << endl;

    cout << endl;
    //multiply的函数类型:int(int, int, int)
    //f2:int()
    function<int()> f2 = bind(&multiply, 3, 4, 5);
    cout << "f2() = " << f2() << endl;

    cout << endl;
    Example ex;
    //成员函数add类型:int(Example *, int, int)
    //f3:int()
    function<int()> f3 = bind(&Example::add, &ex, 10, 20);
    cout << "f3() = " << f3() << endl;

    cout << endl;
    //add的原始类型：int(int, int)
    //f4:int(int)
    function<int(int)> f4 = bind(add, 100, std::placeholders::_1);
    cout << "f4(600) = " << f4(600) << endl;

    cout << endl;
    function<int(string, int)> f5 = bind(add, 100, std::placeholders::_2);
    cout << "f5(\"hello\", 400) = " << f5("hello", 400) << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

