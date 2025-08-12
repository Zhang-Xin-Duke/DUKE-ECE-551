#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    virtual void display() const
    {
        cout << "_base:" << _base << endl;
    }

protected:
    Base(long base)
    : _base(base)
    {
        /* cout << "Base(long)" << endl; */
    }

    
    long _base;
};

#if 0
//成员子对象不能明确继承关系
//如果Base类型只提供了保护属性的构造函数
//那么Base类对象不能作为成员子对象而存在
class Test
{
public:
    Test(long ba)
    : _b1(ba)
    {}
private:
    Base _b1;
};
#endif


class Derived
: public Base
{
public:
    Derived(long ba,long de)
    : Base(ba)//基类子对象的初始化ok，因为能够明确继承关系
    , _derived(de)
    /* , _b1(ba) //不能使用保护属性的构造函数初始化Base类型成员子对象 */
    {
        /* cout << "Derived(long,long)" << endl; */
    }

    void display() const
    {
        cout << "_base:" << _base << endl;
        cout << "_derived:" << _derived << endl;
    }
private:
    long _derived;
    /* Base _b1; */
};


void test0(){
    //Base类只定义一个保护属性的构造函数
    //无法在类外创建对象
    //Base类也属于抽象类
    /* Base base(10); */

    Derived d1(3,5);
    Base * pb = &d1;
    pb->display();
}

int main(void){
    test0();
    return 0;
}
