#include <iostream>
using std::cout;
using std::endl;

void test0(){
    //引用的底层实际上是常量指针(const pointer)
    int num = 100;
    int & ref = num;
    cout << &num << endl;
    cout << &ref << endl;

    ref = 1000;
    cout << num << endl;

    //error
    /* int & ref2; */

    int num2 = 1;
    //引用一经初始化不能更改绑定
    //此处实际是赋值
    ref = num2;
    cout << ref << endl;
    cout << num << endl;

    cout << &num << endl;
    cout << &ref << endl;
    cout << &num2 << endl;


}

int main(void){
    test0();
    return 0;
}
