#include <iostream>
using std::cout;
using std::endl;

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
}

void test0(){
    cout << wd::num << endl;
    wd::func();
    cout << wd2::num << endl;
}

int main(void){
    test0();
    return 0;
}
