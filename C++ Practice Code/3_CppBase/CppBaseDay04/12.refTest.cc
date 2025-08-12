#include <iostream>
using std::cout;
using std::endl;

int gNum = 10;

class Test
{
public:
    int & ref = gNum;
};


void test0(){
    int num = 2;
    int & r = num;
    cout << &r << endl;
    cout << &num << endl;
    cout << endl;

    cout << sizeof(Test) << endl;
    Test t1;
    cout << &t1 << endl;
    cout << &t1.ref << endl;
    cout << &gNum << endl;
}

int main(void){
    test0();
    return 0;
}
