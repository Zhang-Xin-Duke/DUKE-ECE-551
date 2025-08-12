#include <iostream>
using std::cout;
using std::endl;
class Point
{
public:
	Point(double x,double y)
	: _x(x)
	, _y(y)
	{}

    ~Point()
    {
        cout << "~Point()" << endl;
    }

 private:
	double _x;
	double _y;
};

void test0(){
    int a = 10;
    int b = 20;
    cout << &a << endl;
    /* &(a + b);//右值 */

    /* &1; */
    /* &'a'; */
    cout << &"hello" << endl;

    Point pt(2,8);
    /* &Point(3,7); */
}

void test1()
{
    int a = 10;
    int b = 20;
    int & ref = a;
    /* int & ref2 = a + b;//error */
    const int & ref3 = a + b;
    cout << &ref3 << endl;
    
    const int & ref4 = b;

    //右值引用可以绑定右值，不能绑定左值
    //与const左值引用类似，也可以延长右值的生命周期
    int && rr = a + b;
    /* int && rr2 = a; */
    cout << &rr << endl;
}

void test2()
{
    Point && ref = Point(2,5);
    cout << "over" << endl;
}


class A
{
public:
    void func(){}
};

void test3()
{
    //通过无参构造创建了A类对象(左值)
    A a;
    &a;
    a.func();

    //通过无参构造创建了A类临时对象(右值)
    A().func();

    //声明了一个名为a2的函数
    A a2();
    /* a2.func(); */

    //移动构造
    A aa = A();

}


int main(void){
    test2();
    return 0;
}
