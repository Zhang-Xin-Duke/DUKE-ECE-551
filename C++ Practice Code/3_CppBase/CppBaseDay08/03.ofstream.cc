#include <iostream>
#include <fstream>
#include <string>
using std::cerr;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;

void test0(){
    //文件输出流对象绑定的文件不存在
    //那么会创建出这个文件
    //但仍有一些情况会导致ofs进入非goodbit状态
    //
    //如果使用默认的打开模式，
    //那么每次写入前会清空这个文件的内容
    /* ofstream ofs("wd.txt"); */
    ofstream ofs("wd.txt",std::ios::app);

    if(!ofs){
        cerr << "ofstream open file failed" << endl;
        return;
    }

    string line("hello,world\n");
    ofs << line;

    ofs.close();
}

int main(void){
    test0();
    return 0;
}
