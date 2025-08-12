#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(long base)
    : _base(base)
    {
        cout << "Base(long)" << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }
private:
    long _base;
};

class Test
{
public:
    Test(long te)
    : _test(te)
    {
        cout << "Test(long)" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
protected:
    long _test;
};

class Derived
: public Base
{
public:
    Derived(long ba,long de,long te,long bb)
    : Base(ba) //显式调用基类构造函数初始化基类子对象
    , _derived(de)
    , _t1(te)//显式调用对象成员类型的构造函数初始化成员子对象
    , _b1(bb)
    {
        cout << "Derived(long,long)" << endl;
    }

    void print() const
    {
        /* cout << "_base:" << _base << endl; */
        cout << "_derived:" << _derived << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
private:
    long _derived;
    Test _t1;
    Base _b1;//基类类型的对象成员
};


void test0(){
    Derived d1(7,8,9,10);
    cout << sizeof(d1) << endl;
}

int main(void){
    test0();
    return 0;
}
