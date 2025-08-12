#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void checkStatus(const std::istream & is)
{
    cout << "goodbit: " << is.good() << endl;
    cout << "badbit: " << is.bad() << endl;
    cout << "failbit:" << is.fail() << endl;
    cout << "eofbit:" << is.eof() << endl;
    cout << endl;
}

void test0(){
    //创建一个文件输入流对象
    //如果这个输入流对象绑定的是一个不存在的文件
    //会进入failbit状态
    ifstream ifs;
    ifs.open("explicit.cc");

    checkStatus(ifs);
    
    string word("hello");
    ifs >> word;
    cout << word << endl;

    /* int num = 1; */
    /* cin >> num; */
    /* cout << "num:" << num << endl; */
}

//一个一个单词读取
void test1()
{
    ifstream ifs("explicit.cc");

    string word;
    while(ifs >> word)
    {
        cout << word << endl;
    }
    
    /* checkStatus(ifs); */
}

//按行读取
void test2()
{
    string filename("explicit.cc");
    ifstream ifs(filename);

    //兼容C语言的写法
    char arr[100] = {0};
    while(ifs.getline(arr,sizeof(arr)))
    {
        cout << arr << endl;
        memset(arr,0,sizeof(arr));
    }
    
    //思考，为什么没有打印两次文件内容？
    ifs.clear();
    cout << endl;

    //更常用的写法
    string line;
    while(std::getline(ifs,line))
    {
        cout << line << endl;
    }
    
}

int main(void){
    test2();
    return 0;
}
