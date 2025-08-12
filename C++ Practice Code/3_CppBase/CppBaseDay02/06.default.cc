#include <iostream>
using std::cout;
using std::endl;

//函数参数可以赋默认值
//如果相应位置传入了实参，就利用实参初始化形参
//如果相应位置没有传入实参(缺省调用)，就利用默认值初始化形参
void print(int x = 2,int y = 1,int z = 0)
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
}

void test0(){
    print(1,4,8);
    cout << endl;

    //缺省调用
    print(2,6);
    cout << endl;

    print(10);
    cout << endl;

    print();
}

int main(void){
    test0();
    return 0;
}
