#include <iostream>
using std::cout;
using std::endl;

int gNum = 100;

//func1函数的返回值是全局变量gNum的副本
//属于右值
int func1()
{
    return gNum;//会发生复制
}

//func2函数的返回值是绑定到gNum的一个匿名的左值引用
//属于左值
int & func2()
{
    return gNum;
}

//func3函数的返回值是一个右值引用
//是一个右值属性的右值引用
int && func3()
{
    //func3的返回值无法有效地延长a + b这个结果的生命周期
    //实际上函数的返回值是一个悬空引用
    /* int a = 10, b = 20; */
    /* return a + b; */
    return std::move(gNum);
}


void test1()
{
    int && ref = func1(); //此时右值引用本身是左值
    cout << &ref << endl;

/*     int & ref2 = func2(); //ok */
/*     int && ref2 = func2(); //error */
    cout << &func2() << endl;
    cout << &gNum << endl;


    //有名字的右值引用本身是左值
    //没有名字的右值引用本身是右值
    /* &func3(); */
    int && ref2 = func3();
    cout << &ref2 << endl;
}


void test0(){
    int a = 10, b = 20;
    int && ref1 = a + b;
    cout << &ref1 << endl;
}

int main(void){
    test1();
    return 0;
}
