#include <iostream>
using std::cout;
using std::endl;

//宏定义常量没有类型检查，不够安全
/* #define MAX 100 */
#define MAX "hello"

void test0(){
    /* cout << MAX - 1 << endl; */
    /* cout << "hello" + 1 << endl; */

    //更安全
    const int max = 100;
    cout << max << endl;
    /* max = 10; */
    cout << max - 1 << endl;

    //const常量一开始就要初始化
    //初始化之后不能修改其值
    /* const int num; */
    /* num = 100; */
}

int main(void){
    test0();
    return 0;
}
