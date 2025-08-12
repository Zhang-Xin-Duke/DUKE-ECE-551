#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {}

    void print() const
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
private:
    int _ix;
    int _iy;
};

class Point3D
: public Point
{
public:
    Point3D(int x,int y,int z)
    : Point(x,y)//显式调用基类的构造函数来初始化基类子对象
    , _iz(z)
    {}

    void display() const
    {
        cout << "Point3D::display" << endl;
    }
private:
    int _iz;
};

void test0(){
    Point pt(2,5);
    Point3D pt3d1(3,6,7);
    pt.print();
    /* pt.display();//error */

    //通过基类子对象调用print函数
    pt3d1.print();
    pt3d1.display();
  
}

int main(void){
    test0();
    return 0;
}
