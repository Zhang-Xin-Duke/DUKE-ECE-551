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

    Derived(const Derived & rhs)
    //const Base & 可以绑定Derived对象
    : Base(rhs) //显式调用Base的拷贝构造
    , _derived(rhs._derived)
    {
        cout << "Derived的拷贝构造" << endl;
    }

    Derived & operator=(const Derived & rhs)
    {
        cout << "Derived的赋值运算符函数" << endl;
        Base::operator=(rhs);//显式调用Base的赋值运算符函数
        _derived = rhs._derived;
        return *this;
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
    Derived d1(7,8);
    Derived d2 = d1;
    d2.print();

    Derived d3(3,5);
    d3 = d2;
    d3.print();
}

int main(void){
    test0();
    return 0;
}
