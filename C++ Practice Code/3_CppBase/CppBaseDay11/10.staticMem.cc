#include <iostream>
using std::cout;
using std::endl;

class Test
{
public:
    int _a;
    int * _p;
    static int _b;
    static int * _p2;
};
int Test::_b;
/* int * Test::_p2 = nullptr; */
int * Test::_p2;


void test0(){
    Test t1;
    cout << t1._a << endl;
    cout << t1._p << endl;
    cout << Test::_b << endl;
    cout << Test::_p2 << endl;
}

int main(void){
    test0();
    return 0;
}
