#include <iostream>
using std::cout;
using std::endl;

class FFF
{
public:
    static void print(int x){
        cout << "FFF::print:" << x << endl;
    }

    void display(int x){
        cout << "FFF::display:" << x << endl;
    }

    void show(int x)
    {
        cout << "FFF::show:" << x << endl;
    }
};

class DDD
{
public:
    void show(int x)
    {
        cout << "FFF::show:" << x << endl;
    }
};


void print(int x){
    cout << "print:" << x << endl;
}

void display(int x){
    cout << "display:" << x << endl;
}

typedef void (*Function)(int);
typedef void (FFF::*MemFunction)(int);

void test0(){
    Function p;
    p = print;
    p(18);

    //静态成员函数可以用普通的函数指针进行调用
    Function pf = FFF::print;
    /* pf(20); */
    /* FFF::print(20); */

    /* pf = FFF::display; //error */

    //定义成员函数指针时要确定其指向的成员函数的
    //返回类型、参数信息以及类的名称
    void (FFF::*p2)(int) = &FFF::display;
    /* p2 = &FFF::show;//ok */
    /* p2 = &DDD::show;//error */

    FFF fff;

    //.* 成员指针运算符的第一种形式
    (fff.*p2)(100);
    /* fff.display(100); */


    void (FFF::*p3)(int) = &FFF::show;
    (fff.*p3)(200);

    void (FFF::*p4)(int);
    p4 = &FFF::display;

    MemFunction p5;
    p5 = &FFF::show;

    FFF * f = new FFF();
    /* f->display(200); */

    //->*成员指针运算符的第二种形式
    (f->*p4)(400);
    (f->*p5)(500);
    
    delete f;



}

int main(void){
    test0();
    return 0;
}
