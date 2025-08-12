#include <iostream>
using std::cout;
using std::endl;

void print(int x){
    cout << "print:" << x << endl;
}

void display(int x){
    cout << "display:" << x << endl;
}

void show(int x,int y)
{
    cout << x + y << endl;
}

typedef int INT;
typedef void (*Function)(int);

void test0(){
    //定义函数指针时要确定这个函数指针所指向的函数的
    //返回类型、参数信息
    //
    //p1、p2的逻辑类型为void (*)(int)
    //省略形式
    void (*p1)(int) = print;
    p1(10);
    p1 = display;
    p1(20);

    //完整形式
    void (*p2)(int) = &display;
    (*p2)(30);
    p2 = &print;
    (*p2)(40);

    /* p2 = show;//error,函数参数信息不符 */
    //p3的逻辑类型是void (*)(int,int)
    void (*p3)(int,int) = show;
    p3(2,5);

    /* void (*)(int) p4; */
    void (*p4)(int);

    Function p5;
    p5 = print;
    p5(18);

    //使用新类型名称
    //更方便组织
    Function arr[4] = {p1,p2,p4,p5};
    Function * p;

}

int main(void){
    test0();
    return 0;
}
