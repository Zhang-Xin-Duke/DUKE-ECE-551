#include <iostream>

using std::cout;
using std::endl;

class NonCopyable
{
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable &rhs) = delete;
    NonCopyable &operator=(const NonCopyable &rhs) = delete;
};

class Example
: NonCopyable
{
public:
    Example() = default;
    Example(const Example &rhs) = default;
    Example &operator=(const Example &rhs) = default;
    //1、将拷贝构造与赋值运算符删除
    /* Example(const Example &rhs) = delete; */
    /* Example &operator=(const Example &rhs) = delete; */
private:
    //2、将拷贝构造与赋值运算符函数设置为私有的
    /* Example(const Example &rhs); */
    /* Example &operator=(const Example &rhs); */

    //3、可以让派生类继承基类，并且将基类的拷贝构造或者赋值运算符
    //函数删除或者设置为私有的
};

int main(int argc, char *argv[])
{
    Example ex;
    Example ex2 = ex;//error
    Example ex3;
    ex3 = ex;//error
    return 0;
}

