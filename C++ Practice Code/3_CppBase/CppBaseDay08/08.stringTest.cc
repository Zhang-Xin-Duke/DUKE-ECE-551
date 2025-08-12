#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void func1(const string & rhs)
{
    cout << rhs << endl;
}

void func2(const char * pstr)
{
    cout << pstr << endl;
}

void test0(){
    string str1("hello");
    func1(str1);

    //发生隐式转换
    //利用C风格字符串创建了临时的string对象作为实参
    func1("world");

    func2("wangdao");
    func2(str1.c_str());
}



int main(void){
    test0();
    return 0;
}
