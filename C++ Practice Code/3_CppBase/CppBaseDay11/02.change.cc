#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point;

class Complex
{
public:
    Complex(int real,int image)
    : _real(real)
    , _image(image)
    {}

    Complex(const Point &);

    /* Complex & operator=(const Point &); */

    void print() const
    {
        cout << _real << " + "
            << _image << "i" << endl;
    }
private:
    int _real;
    int _image;
};

class Point
{
public:
    explicit
    Point(int x = 0,int y = 0)
    : _ix(x)
    , _iy(y)
    {}

    void print() const
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    operator int()
    {
        return _ix + _iy;
    }

    /* operator Complex() */
    /* { */
    /*     cout << "类型转换函数" << endl; */
    /*     return Complex(_ix,_iy); */
    /* } */

    friend class Complex;
private:
    int _ix;
    int _iy;
};


Complex::Complex(const Point & rhs)
: _real(rhs._ix)
, _image(rhs._iy)
{
    cout << "特殊的构造函数" << endl;
}

/* Complex & Complex::operator=(const Point & rhs) */
/* { */
/*     cout << "特殊的赋值函数" << endl; */
/*     _real = rhs._ix; */
/*     _image = rhs._iy; */
/*     return *this; */
/* } */

void test0(){
    //缺省调用
    Point pt(10);

    //隐式转换
    //由其他类型向自定义类型转换
    //Point pt = Point(1);
    /* Point pt = 1; */
}

void test1()
{
    //由自定义类型向其他类型（内置类型）转换
    Point pt(2,8);
    //利用类型转换函数
    //由pt对象产生一个int型变量
    /* int a = pt.operator int(); */
    int a = pt;
    cout << a << endl;
    /* &(pt.operator int()); //error */

    pt.print();
}

#if 0
void test2()
{
    //由自定义类型向其他类型（其他自定义类型）转换
    Point pt(3,7);

    //需要由Point对象产生Complex对象
    //类型转换函数的思路
    //Complex cx = pt.operator Complex();
    //
    //隐式转换的思路
    //Complex cx = Complex(pt);
    Complex cx = pt;
    cx.print();

    /* int a = 1; */
    /* int b = a; */
    /* Complex cx2(1,2); */
    /* Complex cx3(cx2); */
}
#endif

void test3()
{
    Complex cx(3,6);
    Point pt(2,5);
    //1.类型转换函数的思路
    //cx = pt.operator Complex();
    //
    //2.隐式转换的思路
    //cx = Complex(pt);
    //
    //3.运算符重载的思路
    //cx.operator=(pt);
    //
    //优先级：3 > 1 > 2
    cx = pt;
    cx.print();
}



int main(void){
    test3();
    return 0;
}
