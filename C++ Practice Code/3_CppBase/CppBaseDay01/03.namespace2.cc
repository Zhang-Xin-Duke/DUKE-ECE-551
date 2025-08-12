#include <iostream>
using std::cout;
using std::endl;

/* int num = 1; */

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
    //using编译指令建议放在局部作用域
    //它的效果是将命名空间中的实体引入
    //在using编译指令之后可以直接使用实体名称
    //访问命名空间中的实体
    using namespace wd;
    cout << num << endl;
    func();
}

void test1(){
    using namespace wd2;
    cout << num << endl;
}


int main(void){
    test0();
    return 0;
}
