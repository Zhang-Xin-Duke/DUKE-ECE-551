#include <iostream>
using std::cout;
using std::endl;

//数组指针
void test0(){
    int arr[5] = {1,2,3,4,5};
    //首个元素的首地址
    cout << arr << endl;
    //数组空间的首地址
    cout << &arr << endl;

    cout << arr + 1 << endl;
    cout << &arr + 1 << endl;

    //数组指针就是指向数组的指针
    int (*p)[5] = &arr;
    for(int idx = 0; idx < 5; ++idx){
        cout << (*p)[idx] << " ";
    }
    cout << endl;
}

//指针数组
//元素为指针的数组
void test1(){
    /* int a = 1, b = 2, c = 3; */
    /* int arr[3] = {a,b,c}; */
    /* cout << &a << endl; */
    /* cout << arr << endl; */

    int num1 = 1, num2 = 2, num3 = 3;
    int *p1 = &num1, *p2 = &num2, *p3 = &num3;
    int * arr[3] = {p1,p2,p3};
    for(int idx = 0; idx < 3; ++idx){
        cout << *arr[idx] << " ";
    }
    cout << endl;
}


void func(int x){
    cout << "func:" << x << endl;
}

int func2(){
    cout << "hello" << endl;
    return 1;
}

//函数指针
//指向函数的指针
void test2(){
    //定义函数指针时要确定
    //这类指针可以指向的函数的返回类型和参数信息
    //
    //省略形式
    void (*p)(int) = func;
    p(10);

    int (*p2)() = func2;
    p2();

    //完整形式
    void (*p3)(int) = &func;
    (*p3)(20);
    p3(49);
}


//指针函数
//返回值为指针的函数
//要注意返回的指针所指向的变量本体生命周期应该
//比函数更长
int num = 2000;

int * print(){
    return &num;
}

void test3(){
    /* cout << print() << endl; */
    int * p = print();
    cout << *p << endl;
}



int main(void){
    test3();
    return 0;
}
