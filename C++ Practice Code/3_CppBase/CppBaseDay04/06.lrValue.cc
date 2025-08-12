#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    void print()
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test1(){
    Point(1,2);
    const Point & ref = Point(1,2);
    cout << "over" << endl;
}


void test0(){
    int a = 1;
    int b = 2;
    cout << &a << endl;
    cout << &b << endl;
    //a + b这个表达式的值是一个右值
    /* &(a + b); */

    //最准确的区分方式是取地址
    //能够取地址的内容是左值(持续存活)
    //不能取地址的内容是右值(即将消亡)
    int & ref = a;
    /* int & ref2 = a + b; */

    //const引用可以绑定右值
    //其效果为延长右值的生命周期
    const int & ref3 = a + b;
    const int & ref4 = b;

    /* &1; */
    /* &'a'; */
}



int main(void){
    test1();
    return 0;
}
