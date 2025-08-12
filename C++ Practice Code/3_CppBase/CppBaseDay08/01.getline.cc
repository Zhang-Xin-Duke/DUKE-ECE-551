#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;


//按行读取
void test0()
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
    ifs.seekg(0);
    cout << endl;

    //更常用的写法
    string line;
    while(std::getline(ifs,line))
    {
        cout << line << endl;
    }

    ifs.close();
    
}

int main(void){
    test0();
    return 0;
}
