#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

class Line;

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

    void func(const Line & rhs);

    friend class Line;
private:
    int _ix;
    int _iy;
};

class Line
{
public:
    double distance(const Point & p1,const Point & p2)
    {
        return sqrt(pow(p1._ix - p2._ix,2) +
                pow(p1._iy - p2._iy,2));
    }

    void setPoint(int x,Point & p1)
    {
        p1._ix = x;
    }

    friend class Point;
private:
    int _tt = 100;
};

void Point::func(const Line & rhs)
{
    rhs._tt;
}

void test0(){
    Point pt(0,0);
    Point pt2(3,4);
    /* pt + pt2; */

    Line ll;
    cout << ll.distance(pt,pt2) << endl;

    ll.setPoint(100,pt);
    pt.print();
}

void test1()
{
    int num = 1;
    cout << sizeof(num) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof num << endl;
    /* cout << sizeof int << endl;//error */
}

int main(void){
    test1();
    return 0;
}
