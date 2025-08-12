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

    //Point pt(1,2);
    //Point pt2(pt);
    //
    //const Point rhs = pt;
    //又会触发拷贝构造
    //const Point rhs = pt;
    //const Point rhs = pt;
    //const Point rhs = pt;
    //...
    /* Point(const Point  rhs) */
    /* : _ix(rhs._ix) */
    /* , _iy(rhs._iy) */
    /* { */
    /*     cout << "Point(const Point & rhs)" << endl; */
    /* } */


    
    //建立一个习惯
    //使用对象作为函数参数时
    //首先考虑的形参形式为const引用
    //Point pt(1,2);
    //Point pt2(pt);
    //const的意义在于能够保证函数中不会修改实参的内容
    //以及能够支持对右值属性对象的复制
    Point(const Point & rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        /* rhs._ix = 1000; */
        cout << "Point(const Point & rhs)" << endl;
    }

    void print()
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test1(){
    Point pt(3,7);
    Point pt2 = pt;
    pt.print();
    pt2.print();
}

void test2(){
    //临时对象（匿名的对象）
    //生命周期只有当前行
    /* Point(1,8).print(); */

    Point pt3 = Point(1,8);
}


void test0(){
    int a = 1;
    /* int b = a; */
    int b(a);
    cout << a << endl;
    cout << b << endl;

    Point pt(1,2);
    /* Point pt2 = pt; */
    Point pt2(pt);
    pt.print();
    pt2.print();
}

int main(void){
    test2();
    return 0;
}
