#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:    
#if 0
    Point(double x,double y = 1)
    {
        //函数体中对数据成员进行“初始化”
        //并不是严格意义上的初始化
        //而是理解为赋值
        //
        //类似于
        //double _x;
        //_x = x;
        _x = x;
        _y = y;
        cout << "Point(double,double)" << endl;
    }
#endif

    //用初始化列表的形式定义构造函数
    //初始化列表中对数据成员的初始化是严格意义的初始化
    //
    //数据成员的初始化顺序与声明顺序一致
    //与初始化列表的顺序无关
    /* Point(double x = 2,double y = 1) */
    /* : _x(x)// double _x = x */
    /* , _y(y)// double _y = y */
    /* { */
    /*     cout << "Point(double,double)" << endl; */
    /* } */

    //构造函数在类定义中声明
    //在类定义外实现
    Point(double x = 2,double y = 1);

    void print()
    {
        cout << "(" << _x
            << "," << _y
            << ")" << endl;
    }
private:
    //只能理解为声明
    double _x;
    double _y;
};


Point::Point(double x,double y)
: _x(x)
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

    Point pt2(2.7);
    pt2.print();

    //调用了所有参数都有默认值的有参构造函数
    Point pt3;
    pt3.print();


}

int main(void){
    test0();
    return 0;
}
