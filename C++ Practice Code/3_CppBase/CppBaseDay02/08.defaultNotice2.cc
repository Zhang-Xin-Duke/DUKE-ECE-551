#include <iostream>
using std::cout;
using std::endl;

int add(int x,int y = 1)
{
    return x + y;
}


//已经存在函数重载情况时
//给函数赋默认值需要注意冲突问题
/* int add(int x,int y,int z = 0) */ 
int add(int x,int y,int z)
{
    return x + y + z;
}

void test0(){
    cout << add(1,2,3) << endl;
    cout << add(3,8) << endl;
    cout << add(4) << endl;
}

int main(void){
    test0();
    return 0;
}
