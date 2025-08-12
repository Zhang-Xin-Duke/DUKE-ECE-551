#include <iostream>
using std::cout;
using std::endl;


class Line
{
    class Point
    {
    public:
        Point(int x = 1,int y = 1)
            : _ix(x)
              , _iy(y)
        {}

        void print()
        {
            cout << "(" << _ix
                << "," << _iy
                << ")";
        }
    private:
        int _ix;
        int _iy;
    };
public:
    Line(int x1,int y1,int x2,int y2)
        : _pt1(x1,y1)
          , _pt2(x2,y2)
    {}

    void printLine(){
        _pt1.print();
        cout << "------>";
        _pt2.print();
        cout << endl;
    }

    void func()
    {
        Point pt(1,2);
    }

private:
    Point _pt1;
    Point _pt2;
    int _z = 1;
};

void test0(){
    /* Line::Point pt(1,2); */

    //内存的嵌套结构是由于Line声明了Point类型的对象成员
    //类定义上的嵌套并不会导致内存角度的嵌套关系
    Line ll(1,2,3,4);
    ll.printLine();
    cout << sizeof(Line) << endl;
}



int main(void){
    test0();
    return 0;
}
