#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    static Point * getInstance()
    {
        if(nullptr == _pInstance){
            _pInstance = new Point(1,2);
        }
        return _pInstance;
    }

    void init(int x,int y)
    {
        _ix = x;
        _iy = y;
    }
 
    void print() const
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
    
    static void destroy()
    {
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
  
private:
    //C++11
    Point() = default;
    Point(const Point &) = delete;
    Point & operator=(const Point &) = delete;

    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }
    
    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
    static Point * _pInstance;
};
Point * Point::_pInstance = nullptr;

#if 0
void test0(){
    Point * pt = Point::getInstance();
    Point * pt2 = Point::getInstance();
    cout << pt << endl;
    cout << pt2 << endl;
    pt->print();
    pt2->print();
    /* delete pt; */
    /* delete pt2; */
}
#endif

void test1(){
    //单例对象的规范使用方式
    Point::getInstance()->init(100,200);
    Point::getInstance()->print();
    Point::getInstance()->init(10,20);
    Point::getInstance()->print();
    /* delete Point::getInstance(); */
    /* Point::getInstance()->destroy(); */
    /* Point::getInstance()->destroy(); */

    //即使多次调用，也不会出现double free
    Point::destroy();
    /* Point::destroy(); */
    /* Point::destroy(); */
}

int main(void){
    test1();
    return 0;
}
