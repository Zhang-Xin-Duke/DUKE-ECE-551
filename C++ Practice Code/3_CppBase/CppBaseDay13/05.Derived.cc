#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    /* Base(){} */
    Base(long base = 1)
    : _base(base)
    {
        cout << "Base(long)" << endl;
    }
protected:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long ba,long de)
    //如果在派生类的构造函数的初始化列表中
    //没有显式调用基类的构造函数来初始化基类子对象
    //那么编译器会自动调用基类的默认构造函数
    //来初始化基类子对象
    /* : Base(ba) */
    : _derived(de)
    {
        cout << "Derived(long,long)" << endl;
    }

    void print() const
    {
        cout << "_base:" << _base << endl;
        cout << "_derived:" << _derived << endl;
    }
private:
    long _derived;
};


void test0(){
    cout << sizeof(long) << endl;
    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    Derived d1(7,8);
    d1.print();
}

int main(void){
    test0();
    return 0;
}
