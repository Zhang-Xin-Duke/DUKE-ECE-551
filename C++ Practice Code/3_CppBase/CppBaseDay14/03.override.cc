#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(long base)
    : _base(base)
    {
        /* cout << "Base(long)" << endl; */
    }

    virtual void display() const
    {
        cout << "_base:" << _base << endl;
    }

    virtual void show() const
    {
        cout << "Base::show" << endl;
    }

    //静态成员函数不能设为虚函数
    //因为静态成员函数没有this指针
    /* static virtual void func() */
    /* {} */

    //inline失效
    //因为inline只是一个建议
    //如果建议被采纳，会在编译阶段进行内联的替换
    inline virtual void func2()
    {
        cout << "func2()" << endl;
    }
protected:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long ba,long de)
    : Base(ba)
    , _derived(de)
    {
        /* cout << "Derived(long,long)" << endl; */
    }

    void display() const override
    {
        cout << "_base:" << _base << endl;
        cout << "_derived:" << _derived << endl;
    }
private:
    long _derived;
};


void test0(){
    cout << sizeof(Base) << endl;
    Derived d1(7,8);
    Base * pbase = &d1;
    pbase->display();

    cout << endl;
    //只能理解为隐藏
    //通过派生类对象直接调用虚函数
    //不能称为动态多态
    d1.display();
}

int main(void){
    test0();
    return 0;
}
