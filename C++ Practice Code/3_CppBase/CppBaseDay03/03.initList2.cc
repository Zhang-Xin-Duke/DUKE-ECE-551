#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:    
    Point(){}

    //构造函数在类定义中声明
    //在类定义外实现
    Point(double x,double y);

    void print()
    {
        cout << "(" << _x
            << "," << _y
            << ")" << endl;
    }
private:
    //C++11允许在数据成员声明处进行初始化
    //是一个默认值的含义
    double _x = 1;
    double _y = 2;
};


Point::Point(double x,double y)
: _x(x) // double _x = x
, _y(y)
{
    /* _x; */
    /* _y; */
}

void test0(){
    //类之外这样写是定义
    /* double _y; */

    Point pt(1.2,5.6);
    pt.print();

    Point pt2;
    pt2.print();

    cout << sizeof(pt) << endl;
    cout << sizeof(pt2) << endl;
    cout << sizeof(Point) << endl;

    int a = 1;
    int b = 100;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(int) << endl;


}

int main(void){
    test0();
    return 0;
}
