#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    static Point & getInstance()
    {
        //局部的静态对象
        //多次调用getInstance也只会
        //初始化一次
        static Point pt(1,7);
        return pt;
    }

 
    void print() const
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    /* void func(){ */
    /*     Point pt(1,2); */
    /*     Point pt2 = pt; */
    /* } */
       
    //C++11
    //从一个类中删除拷贝构造函数
    Point(const Point &) = delete;
    Point & operator=(const Point &) = delete;
private:
    Point(int x = 0,int y = 0)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }
    
    ~Point()
    {
        cout << "~Point()" << endl;
    }

    /* Point(const Point & rhs) */
    /* : _ix(rhs._ix) */
    /* , _iy(rhs._iy) */
    /* { */
    /*     cout << "拷贝构造" << endl; */
    /* } */

private:
    int _ix;
    int _iy;
};

void test0(){
    /* &Point::getInstance(); */
    Point & pt = Point::getInstance();
    Point & pt2 = Point::getInstance();
    cout << &pt << endl;
    cout << &pt2 << endl;
}

int main(void){
    test0();
    return 0;
}
