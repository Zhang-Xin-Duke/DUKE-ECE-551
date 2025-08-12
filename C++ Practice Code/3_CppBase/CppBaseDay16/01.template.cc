#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
T add(T t1, T t2)
{
    return t1 + t2;
}

//可以将模板视为一个代码生成器
//模板函数不是手动定义
//而是由函数模板生成的（实例化的）
/* int add(int t1, int t2) */
/* { */
/*     return t1 + t2; */
/* } */

void test0(){
    int i1 = 3, i2 = 4;
    long l1 = 5, l2 = 7;
    short s1 = 4, s2 = 8;
    double d1 = 1.7, d2 = 7.4;
    string str1("hello,");
    string str2("world");

    cout << add(i1,i2) << endl;
    cout << add(l1,l2) << endl;
    cout << add(s1,s2) << endl;

    //隐式实例化
    cout << add(d1,d2) << endl;
    //显式实例化
    cout << add<int>(d1,d2) << endl;
    cout << add(str1,str2) << endl;

    /* vector<int> nums = {1,2,3,4}; */
    /* vector nums = {1,2,3,4};//error */
}

int main(void){
    test0();
    return 0;
}
