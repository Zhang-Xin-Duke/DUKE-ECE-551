#include <iostream>
#include <string>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#if 0
void inputInt(int & value)
{
    cout << "请输入一个整型数据" << endl;
    cin >> value;
    while(!cin.eof()){
        if(cin.bad()){
            cout << "cin has broken" << endl;
            return;
        }else if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "输入整型数据，看清楚点" << endl;
            cin >> value;
        }else{
            cout << value << endl;
            break;
        }
    }
    /* string line; */
    /* cin >> line; */
    /* cout << "line:" << line << endl; */
}
#endif

void inputInt(int & value)
{
    cout << "请输入一个整型数据" << endl;
    //逗号表达式
    //会先执行一次输入
    //再来判断!cin.eof()
    //整个表达式的结果只取决于最后一个逗号后面的内容
    while(cin >> value,!cin.eof()){
        if(cin.bad()){
            cout << "cin has broken" << endl;
            return;
        }else if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "输入整型数据，看清楚点" << endl;
        }else{
            cout << value << endl;
            break;
        }
    }
}

void test0(){
    int num = 10;
    inputInt(num);
}

void test1()
{
    int a = 1;
    cin >> a;

    //流对象作为判断条件
    //如果是goodbit状态自动转换成true
    //否则转换成false
    /* if(cin.good()){ */
    if(!cin){
        /* cout << "goodbit" << endl; */
        cout << "failbit" << endl;
    }
}

void test2()
{
    int num = 1, num2 = 2;
    //cin也可以进行链式输入
    //输入流运算符默认地以空格符、换行符、制表符为分隔符
    cin >> num >> num2;
    cout << "num:" << num << endl;
    cout << "num2:" << num2 << endl;
    ((cout << "num2:") << num2) << endl;

    /* cout << &cin << endl; */
    /* cout << &(cin >> num) << endl; */
}


int main(void){
    test2();
    return 0;
}
