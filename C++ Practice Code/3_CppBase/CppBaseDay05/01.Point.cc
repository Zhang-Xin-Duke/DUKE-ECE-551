#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    //如果一个成员函数的功能不需要对对象的成员进行写操作
    //那么可以将这个成员函数设为const成员函数
    //const Point * const this
    void print() const
    {
        cout << "const版本的print" << endl;
        /* _ix = 100; */
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
 
#if 0
    //Point * const this
    void print() 
    {
        cout << "非const版本的print" << endl;
        /* _ix = 100; */
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
#endif

    void setX(int x)
    {
        _ix = x;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};


void test0(){
    Point pt(1,2);
    pt.setX(10);
    pt.print();
    cout << endl;

    //const对象
    const Point pt2(2,8);
    /* pt2.setX(11); */
    /* pt2 = pt; */
    pt2.print();

}

int main(void){
    test0();
    return 0;
}
