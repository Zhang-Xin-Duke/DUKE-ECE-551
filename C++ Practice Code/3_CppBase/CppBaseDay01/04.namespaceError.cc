#include <iostream>
//using编译指令会一次性引入命名空间中的所有实体
//如果对命名空间的实体不够了解
//也非常有可能写出冲突的代码
/* using namespace std; */

//推荐使用using声明机制
//使用什么就声明什么
using std::cout;
using std::endl;

void xout(){
    printf("hello\n");
}

void test0(){
    xout();
    cout << "world" << endl;
}

int main(void){
    test0();
    return 0;
}
