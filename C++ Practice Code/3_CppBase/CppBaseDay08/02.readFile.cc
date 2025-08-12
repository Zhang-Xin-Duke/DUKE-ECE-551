#include <iostream>
#include <fstream>
using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;

void test0(){
    ifstream ifs("getline.cc");

    if(!ifs)
    {
        cerr << "ifstream open file failed" << endl;
        return;
    }

    cout << ifs.tellg() << endl;
    ifs.seekg(10);
    cout << ifs.tellg() << endl;

    char * data = new char[31]();
    ifs.read(data,30);

    cout << data << endl;

    delete [] data;
    data = nullptr;

    ifs.close();
}

//希望利用read函数，一次性读取文件的所有内容
void test1(){
    ifstream ifs("getline.cc");

    //Linux平台上用vim编辑文件可能会多加一个换行符
    /* ifstream ifs("1.txt"); */

    if(!ifs)
    {
        cerr << "ifstream open file failed" << endl;
        return;
    }

    //tellg获取的位置信息是下标的含义
    /* cout << ifs.tellg() << endl; */
    //seekg设置为end位置，表示尾后位置
    ifs.seekg(0,std::ios::end);
    long length = ifs.tellg();
    /* cout << ifs.tellg() << endl; */

    ifs.seekg(0);
    char * data = new char[length + 1]();
    ifs.read(data,length);

    cout << data << endl;

    delete [] data;
    data = nullptr;

    ifs.close();
}

//希望利用read函数，一次性读取文件的所有内容
void test2(){
    //开始就将文件游标设置在结尾位置
    ifstream ifs("getline.cc",std::ios::ate);

    if(!ifs)
    {
        cerr << "ifstream open file failed" << endl;
        return;
    }

    /* ifs.seekg(0,std::ios::end); */
    long length = ifs.tellg();

    /* ifs.seekg(0); */
    ifs.seekg(0,std::ios::beg);
    char * data = new char[length + 1]();
    ifs.read(data,length);

    cout << data << endl;

    delete [] data;
    data = nullptr;

    ifs.close();
}

int main(void){
    test2();
    return 0;
}
