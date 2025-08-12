#include <unistd.h>
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

void test0(){
    /* for(int i = 0 ; i < 5; ++i) */
    /* { */
    /*     cout << 'a' << endl; */
    /* } */

    for(int i = 0 ; i < 1024; ++i)
    {
        cout << 'a';
    }

    cout.flush();
    sleep(2);
}

void test1(){
    /* cout << "error!!!"; */
    cerr << "error!!!";
    sleep(3);
}

int main(void){
    test1();
    return 0;
}
