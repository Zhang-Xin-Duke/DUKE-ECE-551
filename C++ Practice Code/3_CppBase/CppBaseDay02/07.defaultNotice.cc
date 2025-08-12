#include <iostream>
using std::cout;
using std::endl;

//当函数的声明和实现分离时
//如果要给函数参数赋默认值
//建议写在函数声明中
//
//函数参数赋默认值严格遵循从右往左的顺序
void print(int x,int y = 1);


void test0(){
    //函数声明能够指示调用函数时的形式
    print(2,9);
    print(10);
    /* print(); */
}

void print(int x,int y)
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

int main(void){
    test0();
    return 0;
}
