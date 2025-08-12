#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Point
: public std::enable_shared_from_this<Point>
{
public:
    Point(double x,double y)
    : _x(x)
    , _y(y)
    {}

    //1.
    /* Point * addPoint(Point * pt) */
    /* { */
    /*     _x += pt->_x; */
    /*     _y += pt->_y; */
    /*     return this; */
    /* } */

#if 0
    //2.
    shared_ptr<Point> addPoint(Point * pt)
    {
        _x += pt->_x;
        _y += pt->_y;
        //此时创建的临时对象与sp共用了一个裸指针
        /* return shared_ptr<Point>(this); */

        //重新创建了一份Point资源，交给临时对象管理
        //经过几次移动之后，最终交给sp3管理
        return shared_ptr<Point>(new Point(_x,_y));
    }
#endif
    
    //3.
    shared_ptr<Point> addPoint(Point * pt)
    {
        _x += pt->_x;
        _y += pt->_y;
        return shared_from_this();
     }
    

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
    shared_ptr<Point> sp(new Point(1,2));
    shared_ptr<Point> sp2(new Point(5,6));

    /* cout << sp->addPoint(sp2.get()).use_count() << endl; */
    /* sp->print(); */
    /* sp2->print(); */

    //1.
    //sp3与sp共用了同一个裸指针来创建
    //
    //2.
    shared_ptr<Point> sp3(sp->addPoint(sp2.get()));
    cout << sp.use_count() << endl;
    cout << sp3.use_count() << endl;
    sp->print();
    sp3->print();
    cout << sp.get() << endl;
    cout << sp3.get() << endl;
}

int main(void){
    test0();
    return 0;
}
