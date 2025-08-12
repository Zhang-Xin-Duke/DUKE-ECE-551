#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test0(){
    string str1("hello");
    cout << str1 << endl;
    printf("%s\n",str1.c_str());

    const char * pstr = "hello";
    cout << pstr << endl;
    printf("%s\n",pstr);

    cout << str1.empty() << endl;

    string str2;
    cout << str2.empty() << endl;
}

void test1(){
    string str1("hello");
    cout << str1.size() << endl;

    str1.push_back('!');
    cout << str1 << endl;

    cout << &str1 << endl;
    cout << &(str1.append(5,'.').append("!!!")) << endl;

    string str2("world");
    str1.append(str2);
    str1.append(",wangdao");
    cout << str1 << endl;
}

void test2(){
    string str1("wangdao");
    string str2("ng");
    size_t pos = str1.find(str2,3);
    cout << pos << endl;
}

int main(void){
    test2();
    return 0;
}
