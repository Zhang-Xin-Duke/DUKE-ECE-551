#include <iostream>
using std::cout;
using std::endl;

int gNum = 100;

class Point
{
public:
    Point(int x,int y,int z)
    : _ix(x)
    , _iy(y)
    /* , _ref(z)//引用数据成员所绑定的本体生命周期不够长 */
    , _ref(_ix)
    /* , _ref(gNum) */
    {
        /* &z; */
        cout << "Point(int,int)" << endl;
    }

    void print()
    {
        cout << "(" << _ix
            << "," << _iy
            << "," << _ref
            << ")" << endl;
    }
private:
    int _ix;
    int _iy;
    int & _ref = gNum;//C++11
};


void test0(){
    /* int & ref; */
    Point pt(1,2,3);
    pt.print();
    cout << sizeof(Point) << endl;
}

int main(void){
    test0();
    return 0;
}
