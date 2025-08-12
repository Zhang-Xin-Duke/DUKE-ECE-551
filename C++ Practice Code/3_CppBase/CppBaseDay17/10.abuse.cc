#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;

class Point
{
public:
    Point(double x,double y)
    : _x(x)
    , _y(y)
    {}

    void print() const
    {
        cout << "(" << _x
            << "," << _y
            << ")" << endl;
    }
private:
    double _x;
    double _y;
};

void test0(){
    //人为避免
    Point * pt = new Point(2,5);
    unique_ptr<Point> up(pt);
    unique_ptr<Point> up2(pt);
    up->print();
    up2->print();
}

void test1()
{
    unique_ptr<Point> up(new Point(3,4));
    unique_ptr<Point> up2(new Point(3,4));
    up->print();
    up2->print();
    //人为避免
    up.reset(up2.get());
    cout << up.get() << endl;
    cout << up2.get() << endl;
}

void test2()
{
    //shared_ptr共享资源管理权
    //需要通过拷贝构造或者赋值运算符函数
    //来进行合法的共同管理
    //
    //使用同一个裸指针创建多个shared_ptr仍然是不合理的行为
    //人为避免
    Point * pt = new Point(2,5);
    shared_ptr<Point> sp(pt);
    shared_ptr<Point> sp2(pt);
    sp->print();
    sp2->print();
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
}

void test3()
{
    shared_ptr<Point> sp(new Point(3,4));
    shared_ptr<Point> sp2(new Point(30,40));
    sp->print();
    sp2->print();
    //人为避免
    sp.reset(sp2.get());
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
}

int main(void){
    test3();
    return 0;
}
