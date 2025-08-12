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

        void print() const
        {
            cout << "(" << _ix
                << "," << _iy
                << ")";
        }

        void getLine(const Line & rhs)
        {
            //内部类中访问外部类的公有成员，可以通过对象直接访问
            rhs.printLine();
            //内部类中访问外部类的私有成员，也可以通过对象直接访问
            rhs._data;
            /* rhs._test; */
            //内部类中访问外部类的私有静态成员，可以通过类名作用域访问
            Line::_test;
            //内部类中访问外部类的私有静态成员，
            //甚至可以直接用成员名访问
            _test;
        }

        friend class Line;
    private:
        int _ix;
        int _iy;
        static int _iz;
    };

public:
    Line(int x1,int y1,int x2,int y2)
    : _pt1(x1,y1)
    , _pt2(x2,y2)
    {}

    void printLine() const{
        _pt1.print();
        cout << "------>";
        _pt2.print();
        cout << endl;
    }

    void func()
    {
        //外部类中访问内部类的公有成员，可以通过对象直接访问
        Point pt(1,2);
        pt.print();
        //外部类中访问内部类的私有成员，需要友元声明
        /* pt._ix; */
        Point::_iz;
        /* _iz;//error */
    }
private:
    Point _pt1;
    Point _pt2;
    int _data = 1;
    static int _test;
};
int Line::Point::_iz = 0;
int Line::_test = 1;


int gNum = 1;

class Test
{
    void func()
    {
        _a;
        gNum;
    }

    int _a;
};




void test0(){
}



int main(void){
    test0();
    return 0;
}
