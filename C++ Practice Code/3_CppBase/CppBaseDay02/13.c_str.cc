#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

void test0(){
    /* &'h'; */
    char arr[] = {'h','e','l','l','o','\0'};
    char arr2[] = "world";
    cout << arr << endl;
    cout << arr2 << endl;

    //C++代码中使用C风格的字符串常量
    //要用const char * 进行组织
    //
    /* char * pstr = "wangdao"; */
    const char * pstr = "wangdao";
    /* pstr[0] = 'W'; */
    cout << pstr << endl;

    char * p = new char[strlen(pstr) + 1]();
    strcpy(p,pstr);
    cout << p << endl;
    delete [] p;
    p = nullptr;
}

int main(void){
    test0();
    return 0;
}
