#include <iostream>
using std::cout;
using std::endl;

//外部引入声明
extern int val;
extern void print();

namespace wd
{
extern int num;

extern void display();
}

void test0(){
    cout << val << endl;
    print();

    cout << wd::num << endl;
    wd::display();
}

int main(void){
    test0();
    return 0;
}
