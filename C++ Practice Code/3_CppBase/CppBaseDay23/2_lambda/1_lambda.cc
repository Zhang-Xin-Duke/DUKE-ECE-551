#include <iostream>

using std::cout;
using std::endl;

void test()
{
    int a = 3;
    //[] 捕获列表
    //() 函数的参数列表
    //{} 函数的函数体
    //
    //值捕获：拷贝一份副本到lambda表达式中了,并且默认是不能修改的,如果
    //想修改值捕获的内容，可以使用mutable
    //引用捕获：传递的是引用，并且在lambda表达式中可以修改
    /* [a](int value)mutable->void{ */
    [a](int value)mutable{
        ++value;
        cout << value << "  ";
        ++a;
        cout << "a = " << a << endl;
    }(100);
    cout << endl;

    cout << endl << endl;
    [a](){
        cout << "a11 = " << a <<endl;
    }();
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

