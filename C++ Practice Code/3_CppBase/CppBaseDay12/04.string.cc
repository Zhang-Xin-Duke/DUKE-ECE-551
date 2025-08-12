#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test0(){
    string str1("hello,world!!!!");
    string str2("hello,world!!!!!");
    cout << sizeof(string) << endl;
    cout << "sizeof(str1):" << sizeof(str1) << endl;
    cout << "sizeof(str2):" << sizeof(str2) << endl;

    cout << "&str1:" << &str1 << endl;
    printf("%p\n",&str1[0]);

    cout << endl;
    cout << "&str2:" << &str2 << endl;
    printf("%p\n",&str2[0]);
}

void test1()
{
    string str1("hello,world");
    string str2("hello,world!!!!!!!!");
    cout << "str1.size:" << str1.size() << endl;
    cout << "str2.size:" << str2.size() << endl;
    cout << "str1.capacity:" << str1.capacity() << endl;
    cout << "str2.capacity:" << str2.capacity() << endl;

    string str3 = str2;
    printf("%p\n",&str2[0]);
    printf("%p\n",&str3[0]);

}

int main(void){
    test1();
    return 0;
}
