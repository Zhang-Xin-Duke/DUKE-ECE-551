#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    //有时基类无法给出合适的虚函数的定义
    //之后想要通过动态多态
    //去调用派生类所实现的虚函数
    //那么就可以在基类中声明纯虚函数
    virtual void display() const = 0;
    virtual void print() const = 0;
};

class B
: public A
{
public:
    void display() const override
    {
        cout << "B::display()" << endl;
    }

    void print() const override
    {
        cout << "B::print()" << endl;
    }

};

class C
: public A
{
public:
    void display() const override
    {
        cout << "C::display()" << endl;
    }
};

class D
: public C
{
public:
    /* void display() const override */
    /* { */
    /*     cout << "D::display()" << endl; */
    /* } */

    void print() const override
    {
        cout << "D::print()" << endl;
    }
};

#if 0
void test0(){
    /* A a;//抽象类不能创建对象 */
    B b1;
    A * pa = &b1;
    pa->display();

    C c1;
    pa = &c1;
    pa->display();
}
#endif

void test1()
{
    B b1;
    A & ref = b1;
    ref.display();
    ref.print();

    cout << endl;
    /* C c; */
    D d1;
    A & ref2 = d1;
    ref2.display();
    ref2.print();

}

int main(void){
    test1();
    return 0;
}
