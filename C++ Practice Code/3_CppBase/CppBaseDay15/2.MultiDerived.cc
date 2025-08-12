#include <iostream>
using std::cout;
using std::endl;

class A{
public:
    virtual void a(){ cout << "A::a()" << endl; } 
    virtual void b(){ cout << "A::b()" << endl; } 
    virtual void c(){ cout << "A::c()" << endl; } 
};

class B{
public:
    virtual void a(){ cout << "B::a()" << endl; } 
    virtual void b(){ cout << "B::b()" << endl; } 
    void c(){ cout << "B::c()" << endl; } 
    void d(){ cout << "B::d()" << endl; } 
};

class C
: public A
, public B
{
public:
    virtual void a(){ cout << "C::a()" << endl; } 
    void c(){ cout << "C::c()" << endl; } 
    void d(){ cout << "C::d()" << endl; } 
};

class D
: public C
{
    void c(){ cout << "D::c()" << endl; } 
};

void test0(){
    C c;
    c.a(); //C::a() 隐藏，不通过虚函数表
    /* c.b(); //成员名访问冲突二义性 */ 
    c.c(); //C::c() 隐藏，不通过虚函数表
    c.d(); //C::d() 隐藏 
    
    cout << endl;
    A* pa = &c;
    pa->a(); //C::a() 动态多态
    pa->b(); //A::b() 会通过虚函数表，没有覆盖
    pa->c(); //C::c() 动态多态
    /* pa->d(); //A类没有这个成员函数 */
    
    cout << endl;
    B* pb = &c;
    pb->a(); //C::a() 动态多态
    pb->b(); //B::b() 通过虚函数表，没有覆盖
    pb->c(); //B::c() c函数对于B类而言是普通成员函数
    pb->d(); //B::d() 同上


    cout << endl;
    C * pc = &c;
    pc->a(); //C::a() 会通过虚函数表
    /* pc->b(); //成员名访问冲突二义性 */
    pc->c(); //C::c() c函数对于C类而言是虚函数，会通过虚函数表
    pc->d(); //C::d() 隐藏

    cout << endl;
    D d;
    pc = &d;
    pc->c(); //D::c() 动态多态
}

int main(void){
    test0();
    return 0;
}
