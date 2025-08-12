#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;

void func(int x1, int x2, int x3, const int &x4, int x5)
{
    cout << "x1 = " << x1 << endl
         << "x2 = " << x2 << endl
         << "x3 = " << x3 << endl
         << "x4 = " << x4 << endl
         << "x5 = " << x5 << endl;
}

void test()
{
    int number = 100;
    using namespace  std::placeholders;
    //占位符的整体代表的是函数的形参
    //占位符中的数字代表的是函数的实参
    //实际传参的时候，参数的个数要大于等于占位符中数字的最大值
    //bind默认采用的是值传递（拷贝一份）
    //如果想使用引用传递，可以使用引用的包装器
    //std::ref = reference
    //std::cref = const reference
    auto f = bind(func, 10, _3, _2, std::cref(number), number);
    number = 333;
    f(1, 20, 300, 4000, 11, 22, 33, 44);//多的参数直接扔掉
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

