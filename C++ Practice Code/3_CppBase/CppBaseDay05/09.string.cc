#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test0(){
    string str1;
    string str2("hello");
    cout << str2 << endl;

    string str3 = "hello";
    cout << str3 << endl;

    string str4("wangdao",3);
    cout << str4 << endl;

    string str5 = str3;
    cout << str5 << endl;

    string str6(str5,1,2);
    cout << str6 << endl;

    string str7(5,'a');
    cout << str7 << endl;
}

void test1(){
    string str1("hello,world");

    //迭代器可以理解为广义的指针
    //begin函数返回首迭代器
    //end函数返回尾后迭代器
    
    /* char * ps = str1.begin(); */
    string::iterator it = str1.begin();
    //自动推导出类型
    auto it2 = str1.end();
    cout << *it << endl;

    string str2(it,--it2);
    cout << str2 << endl;
}

void test2(){
    string str1("hello,");
    string str2("world");
    cout << str1 + str2 << endl;

    string str3 = str1 + ',' + str2 + ",wangdao" + '!';
    cout << str3 << endl;
}

int main(void){
    test2();
    return 0;
}
