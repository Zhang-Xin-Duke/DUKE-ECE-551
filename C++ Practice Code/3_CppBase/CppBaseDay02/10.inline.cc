#include <iostream>
using std::cout;
using std::endl;

#define MAX(a, b) ((a) > (b) ? (a) : (b)) 

inline
int max(int x, int y)
{
	return x > y ? x : y;
}

void test0(){
    int a = 10;
    int b = 96;
    int res = max(a,b);
    /* int res = a > b ? a : b; */
    cout << res << endl;

    int res2 = MAX(a,b);
    cout << res2 << endl;
}

void test1(){
    //如果没有最外层的大括号
    //(20)>(10)?(20):(10) + 20
    int res = MAX(20,10) + 20;//res的值是多少？
    //(10)>(20)?(10):(20) + 20
	int res2 = MAX(10,20) + 20;//res2的值是多少？
    cout << res << endl;
    cout << res2 << endl;
}

void test2(){
    int i = 4,j = 3;
    //((i++)>(j)?(i++):(j))
    /* int res = MAX(i++,j); */
    int res = max(i++,j);
    cout << res << endl; //res的值是多少？
    cout << i << endl; //i的值是多少？
}

int main(void){
    test2();
    return 0;
}
