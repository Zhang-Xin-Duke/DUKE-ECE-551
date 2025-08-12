#include <iostream>
using std::cout;
using std::endl;

/* #pragma pack(4) */

class A{
    int _num;
    double _price;
};

class B{
    int _num;
    int _price;
};

class C{
    int _c1;
    int _c2;
    double _c3;
};

class D{
    int _d1;
    double _d2;
    int _d3;
};

class E{
    double _e;
    char _eArr[20];
    int _e2;
    double _e1;
};

class F{
    char _fArr[20];
};

class G{
    char _gArr[20];
    int _g1;
    double _g2;
};

class H
{
    /* char _h; */
};

void test0(){
    /* A a; */
    /* B b; */

    //编译器的占位机制
    //空类对象也会被分配1个字节的空间
    H h1;
    H h2;
    cout << &h1 << endl;
    cout << &h2 << endl;

    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    cout << sizeof(E) << endl;
    cout << sizeof(F) << endl;
    cout << sizeof(G) << endl;
    cout << sizeof(H) << endl;

}

int main(void){
    test0();
    return 0;
}
