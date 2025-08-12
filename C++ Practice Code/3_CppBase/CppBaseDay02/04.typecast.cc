#include <iostream>
using std::cout;
using std::endl;

void test0(){
    /* int * p = (int*)malloc(sizeof(int)); */
    int * p = static_cast<int*>(malloc(sizeof(int)));
    *p = 100;
    delete p;
    p = nullptr;

    int num = 100;
    int * pint = &num;
    /* double * pd = (double*)pint; */
    /* cout << *pd << endl; */

    //static_cast相比与C风格的类型转换
    //可以组织一部分不合理的转换
    //不允许
    /* double * pd2 = static_cast<double*>(pint); */
}

void test1(){
    int num = 100;
    const int * p = &num;
    /* *p = 1000; //error */

    //const_cast可以去除
    //指向常量的指针或者常引用的const属性
    int * p1 = const_cast<int*>(p);
    *p1 = 1000;
    cout << num << endl;

    const int & ref = num;
    /* ref = 2000; */
    int & ref2 = const_cast<int&>(ref);
    ref2 = 2000;
    cout << num << endl;

    /* const int num2 = 1; */
    /* int num3 = const_cast<int>(num2); */
}

void test2(){
    const int num = 100;
    const int * p = &num;
    
    int * p1 = const_cast<int*>(p);
    *p1 = 1000;
    cout << *p1 << endl;
    cout << num << endl;
    cout << p1 << endl;
    cout << &num << endl;


}

int main(void){
    test2();
    return 0;
}
