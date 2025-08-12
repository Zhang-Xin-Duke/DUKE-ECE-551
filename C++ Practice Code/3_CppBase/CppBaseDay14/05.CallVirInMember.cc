#include <iostream>
using std::cout;
using std::endl;

class Base{
public:
    Base(long x)
    : _base(x)
    {}

    virtual void display() const{
        cout << "Base::display()" << endl;
    }

    void func1(){
        display();
        cout << _base << endl;
    }

    void func2(){
        Base::display();
    }
private:
    long _base = 10;
};


class Derived
: public Base
{
public:
    Derived(long base,long derived)
    : Base(base)
    , _derived(derived)
    {}

    void display() const override{
        cout << "Derived::display()" << endl;
    }
private:
    long _derived;
};

void test0(){
    Base base(10);
    Derived derived(1,2);

    base.func1();
    base.func2();

    //这种情况很特别
    //derived对象需要通过基类子对象调用func1函数
    //可以理解为func1函数执行时被加入的this指针是Base*类型
    //this指针指向derived对象，并调用虚函数(func1函数内部)
    //满足了动态多态的所有触发条件
    derived.func1();
    derived.func2();
}
int main(void){
    test0();
    return 0;
}
