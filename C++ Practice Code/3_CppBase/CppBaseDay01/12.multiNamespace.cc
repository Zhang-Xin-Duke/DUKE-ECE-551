#include <iostream>
using std::cout;
using std::endl;

void func();
void func();
void func();
void func();
void func(){}

//error
/* func(); */

//error
/* namespace wd; */

namespace wd
{
int num = 200;
int num2 = 400;

//命名空间作用域中不能直接访问实体
/* num; */
}//end of namespace wd




namespace wd
{
/* int num = 200; */

void print(){
    cout << num << endl;
    cout << "wd::print()" << endl;
}

//error
/* print(); */

void display();
}//end of namespace wd

void wd::display(){
    cout << "wd::display()" << endl;
}

void test0(){
    cout << wd::num << endl;   
    cout << wd::num2 << endl;   
    wd::print();
    wd::display();

}

int main(void){
    test0();
    return 0;
}
