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

    //this指针保存了调用该成员函数的对象的地址值
    //可以理解为指向"本对象"
    //Point * const this
    void print()
    {
        //error
        /* &this; */
        /* this = new Point(1,2); */

        /* this->_ix = 100; //ok */
        cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }

    //编译器会在这个成员函数执行时加入this指针
    //作为参数列表中的第一个参数
    //保存本对象的地址值
    Point & operator=(const Point & rhs)
    {
        cout << "Point类的赋值运算符函数" << endl;
        this->_ix = rhs._ix;
        this->_iy = rhs._iy;
        return *this;
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
    int a = 1;
    int b = 2;
    cout << &(a = b) << endl;
    cout << &a << endl;

    Point pt(1,2);
    Point pt2(3,6);
    pt = pt2;
    /* pt.operator=(pt2);//赋值的本质形式 */
    pt.print();
    pt2.print();
}

int main(void){
    test0();
    return 0;
}
