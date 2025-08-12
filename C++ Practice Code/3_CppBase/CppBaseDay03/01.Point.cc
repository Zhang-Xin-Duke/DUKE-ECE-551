#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point()
    {
        _x = 1;
        _y = 2;
        cout << "Point()" << endl;
    }

    
    Point(double x,double y = 1)
    {
        _x = x;
        _y = y;
        cout << "Point(double,double)" << endl;
    }

#if 0
    //Point pt(2.8);
    Point(double y)
    {
        _x = 1;
        _y = y;
    }

    //Point pt(2.8,6.7,3.4);
    Point(double x,double y,double z)
    {
        _x = x;
        _y = y + z;
    }
#endif

    void setX(double x)
    {
        _x = x;
    }

    void setY(double y)
    {
        _y = y;
    }

    void print()
    {
        cout << "(" << _x
            << "," << _y
            << ")" << endl;
    }
private:
    double _x;
    double _y;
};

void test0(){
    /* int a; */
    /* a = 100; */
    /* cout << a << endl; */

#if 1
    //创建对象时会自动调用构造函数
    //如果手动定义了构造函数，
    //编译器就不会再自动提供默认的无参构造
    Point pt;
    /* pt.setX(1.6); */
    /* pt.setY(2.7); */
    pt.print();
#endif

    Point pt2(1.2,5.6);
    pt2.print();


    //利用无参构造函数初始化对象时，
    //对象名后面不带括号
    //如下写法实际上是声明了一个pt3函数
    /* Point pt3(); */
    /* pt3.print(); */
    
    Point pt4(1.4);
    pt4.print();

}

int main(void){
    test0();
    return 0;
}
