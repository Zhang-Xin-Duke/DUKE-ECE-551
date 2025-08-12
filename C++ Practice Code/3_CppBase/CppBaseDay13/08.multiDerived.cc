#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    A(){ cout << "A()" << endl; }
    ~A(){ cout << "~A()" << endl; }
    void print() const{
        cout << "A::print()" << endl;
    }
};

class B
{
public:
    B(){ cout << "B()" << endl; }
    ~B(){ cout << "~B()" << endl; }
    void show() const{
        cout << "B::show()" << endl;
    }
};

class C
{
public:
    C(){cout << "C()" << endl; }
    ~C(){ cout << "~C()" << endl; }
    void display() const{
        cout << "C::display()" << endl;
    }
};


class D
/* : public A,B,C//公有继承A，私有继承B和C */
: public A
, public B
, public C
{
public:
    D(){ cout << "D()" << endl; }
    ~D(){ cout << "~D()" << endl; }
};

void test0(){
    //创建D类对象，马上调用D类的构造函数
    //在执行过程中调用基类的构造函数完成基类子对象初始化
    //会根据继承声明的顺序初始化
    //最终销毁时，马上调用D类的析构函数
    //然后根据继承声明的逆序调用基类的析构函数
    D d1;
    d1.print();
    d1.show();
    d1.display();
}

int main(void){
    test0();
    return 0;
}
