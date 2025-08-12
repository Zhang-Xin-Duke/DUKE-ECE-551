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

    
    //将一个类声明为Point的友元类
    //那么这个类的所有成员函数
    //都可以通过Point对象直接访问Point的私有成员
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

};


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
