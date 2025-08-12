#include <iostream>
using std::cout;
using std::endl;

int num = 1;

namespace wd
{
int num = 10;

void func(){
    cout << "wd::func()" << endl;
}
}//end of namespace wd

namespace wd2
{
int num = 20;
}//end of namespace wd2

void test0(){
    using wd::num;
    using wd::func;
    cout << num << endl;
    func();
}

void test1(){
    using wd2::num;
    cout << num << endl;
}

void test2()
{
    using wd::num;
    /* using wd2::num; */
    cout << num << endl;
}


int main(void){
    /* test0(); */
    /* test1(); */
    test2();
    return 0;
}
