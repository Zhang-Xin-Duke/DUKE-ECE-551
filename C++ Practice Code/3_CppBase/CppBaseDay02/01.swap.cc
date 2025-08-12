#include <iostream>
using std::cout;
using std::endl;

//值传递，初始化形参时实际上是复制了实参
void swap(int x,int y)
{
    int temp = x;
    x = y;
    y = temp;
}

//地址传递
void swap2(int * px,int * py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

//引用传递
//初始化形参时就是
//int & x = a
//int & y = b
//函数体中操作引用就是操作实参本身
void swap3(int & x,int & y)
{
    int temp = x;
    x = y;
    y = temp;
}

//既避免传参复制
//又能确保函数体中不会通过这个引用形参改变实参
//const引用底层就是双重const限定的指针
void print(const int & x){
    /* x = 100; */
    cout << x << endl;
}

void test1(){
    int a = 10;
    print(a);
    cout << a << endl;
}


void test0(){
    int a = 1;
    int b = 2;
    /* swap(a,b); */
    /* swap2(&a,&b); */
    swap3(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

int main(void){
    test1();
    return 0;
}
