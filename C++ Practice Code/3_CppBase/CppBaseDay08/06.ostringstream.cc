#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::ostringstream;
using std::string;

void test0(){
    int num1 = 123;
    int num2 = 456;

    ostringstream oss;
    //将各种类型的数据传输到字符串输出流对象的缓冲区
    //然后可以利用str函数将缓冲区中的内容拼接成string
    oss << "num1 = " << num1 << ", num2 = " << num2;
    string line = oss.str();
    cout << line << endl;

    string l1("num1 = ");
    string l2 = l1 + std::to_string(num1) + ",num2 = " 
                + std::to_string(num2);   
    cout << l2 << endl;
}

int main(void){
    test0();
    return 0;
}
