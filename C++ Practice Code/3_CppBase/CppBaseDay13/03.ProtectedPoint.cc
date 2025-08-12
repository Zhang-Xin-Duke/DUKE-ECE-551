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
protected:
    int _ix;
private:
    int _iy;
};

class Point3D
: protected Point
{
public:
    Point3D(int x,int y,int z)
    : Point(x,y)//显式调用基类的构造函数来初始化基类子对象
    , _iz(z)
    {}

    void display() const
    {
        cout << "Point3D::display" << endl;
        print();
        cout << _ix << endl; 
        /* cout << _iy << endl; */ 
    }
private:
    int _iz;
};

class Point4D
: public Point3D
{
    void func()
    {
        print();
        cout << _ix << endl;
    }
};



void test0(){
    Point3D pt3d1(3,6,7);
    /* pt3d1.print(); */

    cout << endl;
    pt3d1.display();

    /* pt3d1._ix; */
    /* pt3d1._iy; */
      
}

int main(void){
    test0();
    return 0;
}
