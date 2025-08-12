#include <iostream>
#include <functional>
#include <string>

using std::cout;
using std::endl;
using std::bind;
using std::function;
using std::string;

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
    /* int data(){ return 10; } */
    int data = 123;//C++11中可以在声明数据成员的时候直接初始化
};

void test()
{
    Example ex;
    function<int()> f = bind(&Example::add, &ex, 10, 20);
    cout << "f() = " << f() << endl;

    cout << endl;
    function<int()> f2 = bind(&Example::data, &ex);
    cout << "f2() = " << f2() << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

