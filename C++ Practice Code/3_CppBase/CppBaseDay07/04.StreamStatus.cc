#include <iostream>
#include <limits>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

void checkStatus(const istream & is)
{
    cout << "goodbit: " << is.good() << endl;
    cout << "badbit: " << is.bad() << endl;
    cout << "failbit:" << is.fail() << endl;
    cout << "eofbit:" << is.eof() << endl;
    cout << endl;
}


void test0(){
    checkStatus(cin);

    int num = 1;
    cin >> num;
    cout << "num:" << num << endl;

    if(!cin.good()){
        //将流的状态恢复为goodbit状态
        cin.clear();
        //清空缓冲区
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    checkStatus(cin);

    string line;
    cin >> line;
    cout << "line:" << line << endl;


    /* int num2 = 2; */
    /* cin >> num2; */
    /* cout << "num2:" << num2 << endl; */
    /* checkStatus(cin); */
}

int main(void){
    test0();
    return 0;
}
