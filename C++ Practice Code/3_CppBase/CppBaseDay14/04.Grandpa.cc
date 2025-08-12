#include <iostream>
using std::cout;
using std::endl;

class Grandpa
{
public:
    Grandpa(){ cout << "Grandpa()" << endl; }
    ~Grandpa(){ cout << "~Grandpa()" << endl; }

    virtual void func1() {
        cout << "Grandpa::func1()" << endl;
    }

    virtual void func2(){
        cout << "Grandpa::func2()" << endl;
    }
};

class Parent
: public Grandpa
{
public:
    //在构造函数和析构函数中
    //通过this指针调用虚函数，这个虚函数会被
    //解析为当前类的版本
    //也就是说只能看到本层及以上的具体实现
    Parent(){
        cout << "Parent()" << endl;
        func1();//构造函数中调用虚函数
    }

    ~Parent(){
        cout << "~Parent()" << endl;
        func2();//析构函数中调用虚函数
    }
 
    void func1() {
        cout << "Parent::func1()" << endl;
    }

    void func2() {
        cout << "Parent::func2()" << endl;
    }

};

class Son
: public Parent
{
public:
    Son() { cout << "Son()" << endl; }
    ~Son() { cout << "~Son()" << endl; }

    void func1() {
        cout << "Son::func1()" << endl;
    }

    void func2() {
        cout << "Son::func2()" << endl;
    }
};

//确定Son类中的func1和func2是不是虚函数
//可以用override验证
//还有一种方式
//继续往下派生Grandson,尝试覆盖func1和func2
//Son * ps = &grandson
//ps->func1; 看一看会不会触发动态多态

void test0(){
    Son ss;
    /* Grandpa * p = &ss; */
    /* p->func1(); */
    /* p->func2(); */
}

int main(void){
    test0();
    return 0;
}
