#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

void test0(){
    int * p = new int[10]();
    
    for(int idx = 0; idx < 10; ++idx){
        p[idx] = idx;
    }

    for(int idx = 0; idx < 10; ++idx){
        cout << p[idx] << " ";
    }
    cout << endl;
    delete [] p;
    p = nullptr;


    /* int * p3 = new int{3}; */
    int * p2 = new int[5]{1};
    for(int idx = 0; idx < 5; ++idx){
        cout << p2[idx] << " ";
    }
    cout << endl;

    delete [] p2;
    p2 = nullptr;


    /* cout << p2 << endl; */
    /* delete [] p2; */
    /* cout << p2 << endl; */
    /* cout << *p2 << endl; */
}

void test1(){
    //C++中使用C风格的字符串常量的做法
    const char * pstr1 = "hello";
    const char * pstr2 = "wangdao";

    /* char * p = new char[6]{"hello"};//不是所有的平台都可以通过 */
    /* char * p = new char[6]{'h','e','l','l','o'}; */
    /* char * p = new char[6](); */

    cout << strlen(pstr1) << endl;
    cout << sizeof(pstr1) << endl;

    char * p = new char[strlen(pstr1) + 1]();
    strcpy(p,pstr1);

    //输出流运算符对char*有默认重载效果
    //会自动进行访问
    cout << p << endl;
    
    delete [] p;
    p = new char[strlen(pstr2) + 1]();
    strcpy(p,pstr2);
    cout << p << endl;
    delete [] p;
    p = nullptr;
}


int main(void){
    test1();
    return 0;
}
