#include <iostream>
using std::cout;
using std::endl;

template <typename T>
T add(T t1, T t2)
{
    cout << "模板一" << endl;
    return t1 + t2;
}

//除了模板声明的这一句
//函数模板的定义是非常灵活的
//可以和以前定义普通函数一样，写出各种类型
/* template <class T1,class T2> */
/* double add(T1 t1, T2 t2) */
/* {//...} */

template <class T1,class T2>
T1 add(T1 t1, T2 t2)
{
    cout << "模板二" << endl;
    return t1 + t2;
}


void test0(){
    int i1 = 3, i2 = 4;
    long l1 = 5, l2 = 7;
    double d1 = 3.5, d2 = 7.9;

    cout << add<long>(i1,l2) << endl;
    //当只存在第一个模板时
    //如果显式实例化时，指定的模板参数不合适
    //可能造成精度损失
    cout << add<int>(i2,d1) << endl;

    //隐式实例化通过第二个模板完成
    cout << add(d2,i1) << endl;
    cout << add(i2,d1) << endl;
}

int main(void){
    test0();
    return 0;
}
