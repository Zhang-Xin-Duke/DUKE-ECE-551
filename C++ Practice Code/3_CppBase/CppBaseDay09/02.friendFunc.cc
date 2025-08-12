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

    //将一个普通函数声明为类的友元函数
    //那么在这个普通函数中可以通过类对象访问类的私有成员
    friend
    double distance(const Point & p1,const Point & p2);
private:
    int _ix;
    int _iy;
};

double distance(const Point & p1,const Point & p2)
{
    return sqrt(pow(p1._ix - p2._ix,2) +
                pow(p1._iy - p2._iy,2));
}


void test0(){
    Point pt(0,0);
    /* pt._ix; */
    Point pt2(3,4);
    cout << distance(pt,pt2) << endl;
}

int main(void){
    test0();
    return 0;
}
