#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    void print() const{
        cout << "A::print()" << endl;
    }
    double _a;
};

class B
: public A
{
public:
    double _b;
};

class C
: public A
{
public:
    double _c;
};

class D
: public B
, public C
{
public:
    void print() const
    { 
        cout << "D::print()" << endl;
        /* cout << "A::print()" << endl; */
    }

    double _d;
};

void test0(){
    cout << sizeof(D) << endl;
    D d1;


    //除了使用类作用域，也可以在D类中重新定义print函数
    //对A类的print函数形成隐藏
    //但是没有本质上解决存储二义性问题
    //如果A类有多个成员都需要通过D类对象直接访问
    //那么需要在D类中逐一实现隐藏
    d1.print();
    /* d1.A::print();//error */
    d1.B::print();
    d1.C::print();

}

int main(void){
    test0();
    return 0;
}
