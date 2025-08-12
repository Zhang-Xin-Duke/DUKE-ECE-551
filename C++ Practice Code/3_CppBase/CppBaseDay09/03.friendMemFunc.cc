#include <math.h>
#include <iostream>
using std::cout;
using std::endl;

//前向声明
class Point;

class Line
{
public:
    double distance(const Point & p1,const Point & p2);
    void setPoint(int x,Point & p1);
};

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

    //将另一个类的单个的成员函数声明为Point类的友元函数
    friend double Line::distance(const Point & p1,const Point & p2);
    friend void Line::setPoint(int x,Point & p1);
private:
    int _ix;
    int _iy;
};

double Line::distance(const Point & p1,const Point & p2)
{
    return sqrt(pow(p1._ix - p2._ix,2) +
                pow(p1._iy - p2._iy,2));
}

void Line::setPoint(int x,Point & p1)
{
    p1._ix = x;
}

void test0(){
    Point pt(0,0);
    Point pt2(3,4);

    Line ll;
    cout << ll.distance(pt,pt2) << endl;

    ll.setPoint(100,pt);
    pt.print();
}

int main(void){
    test0();
    return 0;
}
