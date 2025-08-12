#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    /* Point(){} */
    Point(int x = 1,int y = 1)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    void print()
    {
        cout << "(" << _ix
            << "," << _iy
            << ")";
    }

    ~Point()
    {
        cout << "~Point()" << endl;
        cout << _ix << " " << _iy << endl;
    }
private:
    int _ix;
    int _iy;
};

class Line
{
public:
    Line(int x1,int y1,int x2,int y2)
    //如果在Line构造函数的初始化列表中
    //没有显式调用Point的构造函数
    //那么编译器会自动调用Point的无参构造
    //或者所有参数都有默认值的有参构造
    //来初始化对象成员
    : _pt1(x1,y1) //Point _pt1(x1,y1)  
    , _pt2(x2,y2)
    {
        cout << "Line(int*4)" << endl;
    }

    void printLine(){
        _pt1.print();
        cout << "------>";
        _pt2.print();
        cout << endl;
    }

    ~Line()
    {
        cout << "~Line()" << endl;
    }
private:
    //Line类声明了Point类型的对象成员
    Point _pt1;
    Point _pt2;
    int _iz = 10;
};

void test0(){
    //创建Line对象马上调用Line构造函数
    //Line构造函数执行过程中调用两次Point的构造函数
    //(根据_pt1/_pt2声明的顺序)
    Line ll(1,2,3,4);
    ll.printLine();
    //从内存角度来说，
    //Line对象中存在两个Point类型的成员子对象
    cout << sizeof(Line) << endl;
    //Line对象销毁时马上调用Line的析构函数
    //Line析构函数执行完后调用两次Point的析构函数
    //(根据_pt1/_pt2声明的逆序)
}

int main(void){
    test0();
    return 0;
}
