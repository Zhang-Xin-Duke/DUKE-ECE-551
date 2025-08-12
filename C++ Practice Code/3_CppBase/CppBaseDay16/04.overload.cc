#include <iostream>
using std::cout;
using std::endl;

template <typename T>
T add(T t1, T t2)
{
    cout << "函数模板" << endl;
    return t1 + t2;
}

//普通函数的效率比函数模板更高
//故而优先级也更高
int add(int t1, int t2)
{
    cout << "普通函数" << endl;
    return t1 + t2;
}

void test0(){
    int x = 2, y = 4;
    cout << add(x,y) << endl;
    cout << add<int>(x,y) << endl;
}

int main(void){
    test0();
    return 0;
}
