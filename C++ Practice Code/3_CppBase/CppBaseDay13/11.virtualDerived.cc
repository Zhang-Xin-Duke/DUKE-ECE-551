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

//中间层基类虚拟继承顶层基类
class B
: virtual public A
{
public:
    double _b;
};

class C
: virtual public A
{
public:
    double _c;
};

class D
: public B
, public C
{
public:
    double _d;
};

void test0(){
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    D d1;
    d1.print();
}

int main(void){
    test0();
    return 0;
}
