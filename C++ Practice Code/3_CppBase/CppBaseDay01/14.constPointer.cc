#include <iostream>
using std::cout;
using std::endl;

void test0(){
    int num1 = 100;
    int num2 = 200;

    //const在*号前面的
    //指向常量的指针(pointer to const)
    //不能通过这种指针直接修改其指向的值
    //但是这种指针可以修改指向
    const int * p = &num1;
    /* *p = 1000; */
    p = &num2;
    /* num1 = 1000; */

    //效果同上
    int const * p2 = &num1;
    /* *p2 = 1000; */
    p2 = &num2;
}

void test1(){
    int num1 = 100;
    int num2 = 200;

    //const在*号后面的
    //常量指针(const pointer)
    //可以通过指针修改其指向的值
    //但是不能修改指针的指向
    int * const p = &num1;
    *p = 1000;
    cout << num1 << endl;
    /* p = &num2; */
}

void test2(){
    const int num = 10;
    int num2 = 100;
    //指向常量的指针指向变量时
    //不能通过指针修改这个变量的值
    //但是变量本身还是可以修改的
    //
    //只有指向常量的指针才能指向常量
    //此时，通过指针不能修改这个常量的值
    //const常量本身也不能直接进行修改操作
    /* const int * p = &num; */

    //双重const限定的指针
    const int * const p = &num;

    /* *p = 100; */
    /* num = 100; */
    /* p = &num2; */
}

int main(void){
    test1();
    return 0;
}
