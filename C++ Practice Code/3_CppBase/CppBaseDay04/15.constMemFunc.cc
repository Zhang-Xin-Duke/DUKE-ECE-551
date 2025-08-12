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

    //const Point * const this
    void print() const
    {
        /* this = nullptr; */
        /* this->_ix = 100; */
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
private:
    int _ix;
    int _iy;
};


void test0(){
    Point pt(1,2);
    pt.print();
}

int main(void){
    test0();
    return 0;
}
