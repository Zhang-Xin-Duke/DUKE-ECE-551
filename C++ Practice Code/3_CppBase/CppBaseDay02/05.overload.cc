#include <iostream>
using std::cout;
using std::endl;


//在同一个作用域中，可以定义一组同名的函数
//函数参数的类型、顺序、个数任一不同即可
//此时这些函数形成函数重载关系（overload）
//与函数的返回值无关
int add(int x,int y)
{
    cout << "函数一" << endl;
    return x + y;
}

double add(double x,double y)
{
    cout << "函数二" << endl;
    return x + y;
}

double add(double x,int y)
{
    cout << "函数三" << endl;
    return x + y;
}

/* extern "C" */
/* { */

double add(int x,double y)
{
    cout << "函数四" << endl;
    return x + y;
}

double add(int x,double y,double z)
{
    cout << "函数五" << endl;
    return x + y + z;
}
/* int add(int x,double y) */
/* { */
/*     return x + y; */
/* } */

/* } */

void test0(){
    int a = 1, b = 2;
    double c = 1.3, d = 2.9;
    cout << add(a,b) << endl;
    cout << add(c,d) << endl;
    cout << add(c,a) << endl;
    cout << add(b,d) << endl;
    cout << add(b,c,d) << endl;
}

int main(void){
    test0();
    return 0;
}
