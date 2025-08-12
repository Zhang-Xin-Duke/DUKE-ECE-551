#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::istringstream;
using std::string;

void test0(){
    /* string str1("123 abc"); */
    string str1("123 456");
    int num1 = 1;
    int num2 = 2;

    //字符串输入流
    //iss的缓冲区会复制一份str1的内容
    istringstream iss(str1);
    //可以将一个比较长的string的内容进行拆分、解析
    //拆分，输入流运算符默认以空格符、换行符、制表符为分隔符
    //解析，可以将string的一部分转换成其他类型
    iss >> num1 >> num2;
    cout << "num1:" << num1 << endl;
    cout << "num2:" << num2 << endl;

    cout << str1 << endl;

}

int main(void){
    test0();
    return 0;
}
