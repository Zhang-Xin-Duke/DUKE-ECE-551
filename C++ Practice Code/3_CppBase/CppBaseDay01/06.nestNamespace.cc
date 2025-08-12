#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
int val = 1;

void func(){
    cout << "wd::func()" << endl;
}

namespace cpp
{
int val = 100;

void func(){
    cout << "wd::cpp::func()" << endl;
}
}//end of namespace cpp
}//end of namespace wd

void test0(){
    cout << wd::cpp::val << endl;
    wd::cpp::func();

    cout << wd::val << endl;
    wd::func();
}

void test1(){
    using namespace wd::cpp;
    cout << val << endl;
    func();

    /* using namespace wd; */
    /* cout << val << endl; */
    /* func(); */
}

void test2(){
    using wd::cpp::val;
    using wd::cpp::func;//只写函数名
    cout << val << endl;
    func();
}

int main(void){
    test2();
    return 0;
}
