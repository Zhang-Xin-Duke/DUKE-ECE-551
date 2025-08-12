#include <iostream>
using std::cout;
using std::endl;

int gNum = 1;
const int cgNum = 23;

namespace wd
{
int wNum = 22;
}

void test0(){
    int lNum1 = 100;
    int lNum2 = 200;
    const int cNum = 1;
    cout << "&cNum:" << &cNum << endl;
    cout << "&lNum2:" << &lNum2 << endl;
    cout << "&lNum1:" << &lNum1 << endl;

    cout << endl;
    int * p = new int(10);
    /* cout << "&p:" << &p << endl; */
    int * p2 = new int(20);
    cout << "p2:" << p2 << endl;
    cout << "p :" << p << endl;
    delete p;
    p = nullptr;
    delete p2;
    p2 = nullptr;

    cout << endl;
    static int sNum = 2;
    cout << "&sNum:" << &sNum << endl;
    cout << "&wNum:" << &wd::wNum << endl;
    cout << "&gNum:" << &gNum << endl;

    cout << endl;
    const char * pstr = "hello";
    /* cout << &pstr << endl; */

    //<<默认重载效果，会自动访问
    /* cout << pstr << endl; */
    cout << &"hello" << endl;
    cout << static_cast<void*>(const_cast<char*>(pstr)) << endl;
    printf("%p\n",pstr);

    cout << "&cgNum:" << &cgNum << endl;

    cout << endl;
    //对于函数指针也有默认效果
    //非空指针转换为true
    //空指针转换成false
    /* cout << &test0 << endl; */
    printf("%p\n",&test0);
}

int main(void){
    test0();
    printf("%p\n",&main);
    return 0;
}
