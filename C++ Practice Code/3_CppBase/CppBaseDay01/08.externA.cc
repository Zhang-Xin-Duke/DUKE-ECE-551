#include <iostream>
using std::cout;
using std::endl;

int val = 100;

void print(){
    cout << "print()" << endl;
}

namespace wd
{
int num = 1000;

void display(){
    cout << "wd::display()" << endl;
}

}//end of namespace wd

