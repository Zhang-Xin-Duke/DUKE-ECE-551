#include<iostream>
#include <ostream>
using std::cout; 
using std::endl;

template<typename T>
T add(T t1, T t2)
{
    cout << "调用第一个模版参数" << endl;
    return t1 + t2;
}


template<typename T1, typename T2>
T1 add(T1 t1, T2 t2)
{  
    cout << "调用第二个模版参数" << endl;
    return t1 + t2;
}
#if 0
void test0(){
    int i1 = 3, i2 = 4; 
    long l1 = 10, l2 = 20;
    double d1 = 1.1, d2 = 2.2;
    cout << add(i1, i2) << endl;
    cout << add(l1, l2) << endl;
    cout << add<int>(i1, i2) << endl;
    //此时调用的是第二个模版函数
    cout << add(i1, l2) << endl;

    cout << add(i2,d1)<<endl;
}
#endif 

void test1(){
    //除了模版声明这一句函数模版声明是非常灵活的可以和原来定义普通函数一样写出各种类型
    int x = 10;
    double y = 3.8; 
    //调用第二个模版函数
    cout << add(x, y) << endl;
    cout << add <double,int>(x,y) <<endl; 
    //调用第一个模版函数
    cout << add (x,x) <<endl; 
    //调用第二个模版函数，原因：使用第二个模版的时候两个都不需要转换，但是第一个模版需要转换
    //分析：T1被指定为int, T2被推倒为double
    //匹配规则：对参数进行尽可能少的转换
    cout << add<int>(x,y) <<endl; 
    
    //调用模版一：因为
    cout << add<int>(y,x)<< endl;
}