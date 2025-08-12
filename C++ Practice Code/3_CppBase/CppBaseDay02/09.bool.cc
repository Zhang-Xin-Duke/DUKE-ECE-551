#include <iostream>
using std::cout;
using std::endl;

void test0(){
    int b1 = true;
    bool b2 = false;
    cout << b1 << endl;
    cout << b2 << endl;

    bool b3 = 3;
    bool b4 = 0;
    bool b5 = -1;
    if(b5){
        cout << "hello" << endl;
    }

    cout << sizeof(bool) << endl;

}

int main(void){
    test0();
    return 0;
}
