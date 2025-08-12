#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int x,int y)
    //const数据成员需要进行严格意义上的初始化
    : _ix(x)//const int _ix = x
    , _iy(y)//const int _iy = y
    {
        //严格意义上属于赋值
        /* _ix = x; */
        /* _iy = y; */
        cout << "Point(int,int)" << endl;
    }

    /* void setX(int x) */
    /* { */
    /*     _ix = x; */
    /* } */
    
#if 0
    Point & operator=(const Point & rhs)
    {
        /* _ix = rhs._ix; */
        /* _iy = rhs._iy; */
        return *this;
    }
#endif

    void print()
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
private:
    //C++11允许在声明时给出默认值
    const int _ix = 100;
    const int _iy = 200;
};


void test0(){
    /* const int a; */

    Point pt(1,2);
    pt.print();

    Point pt2 = pt;

    //一个类如果声明了const数据成员
    //那么该类对象赋值时要注意
    /* pt2 = pt; */
}

int main(void){
    test0();
    return 0;
}
