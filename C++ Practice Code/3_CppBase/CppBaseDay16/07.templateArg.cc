#include <iostream>
using std::cout;
using std::endl;

//T和kBase都是模板参数
//T属于类型参数
//kBase属于非类型参数
template <class T = int, int kBase = 10>
T multiply(T x, T y)
{
    return x * y * kBase;
}

template <class T1 = int,class T2 = int>
T1 add(T2 x,T2 y)
{
    return x + y;
}

void test0(){
    //指定 > 推导 > 默认值
    cout << multiply<int,10>(3,7) << endl;
    cout << multiply(1.4,1.4) << endl;
    cout << multiply(1.5,1.5) << endl;
    cout << multiply<int>(1.5,1.5) << endl;

    /* cout << multiply(10,4.5) << endl; */
    /* cout << multiply('a',4) << endl; */

    //没有指定，也无法推导的情况下
    //才会用上模板参数的默认值
    cout << add<int>(1,3) << endl;
    cout << add(1,3) << endl;
}

int main(void){
    test0();
    return 0;
}
