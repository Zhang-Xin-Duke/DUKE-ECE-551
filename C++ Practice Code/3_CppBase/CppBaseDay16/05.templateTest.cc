#include <iostream>
using std::cout;
using std::endl;

template <class T>
T add(T t1,T t2);


void test0(){
    cout << add(3,5) << endl;
}

template <class T>
T add(T t1,T t2)
{
    return t1 + t2;
}

int main(void){
    test0();
    return 0;
}
