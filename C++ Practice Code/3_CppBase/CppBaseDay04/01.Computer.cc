#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
    Computer(const char * brand,double price)
    //char * _brand = new char[strlen(brand) + 1]();
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        strcpy(_brand,brand);
        cout << "Computer(const char *,double)" << endl;
    }

    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

    ~Computer()
    {
        cout << "~Computer()" << endl; 
        if(_brand)
        {
            delete [] _brand;
            _brand = nullptr;
        }
    }
private:
    char * _brand;
    double _price;
};

void test0(){
    Computer pc("Dell",7000);
    pc.print();

    //对象销毁时一定会自动调用析构函数
    //手动调用析构函数并不代表对象被销毁
    //
    //不要手动调用析构函数
    //让对象销毁时自动调用
    pc.~Computer();
    pc.print();


    //回收的工作如果在类定义之外进行
    //由于_brand是私有的数据成员
    //无法类外访问，所以无法回收
    //应该在类定义中进行回收工作
    /* delete [] pc._brand; */

    Computer pc2("Lenovo",6000);
    pc2.print();
}

void test1(){
    int num = 100;
    int * p = &num;
    cout << p << endl;
    p = nullptr;
    cout << p << endl;

    char * p2 = nullptr;

    //<<运算符对char*有默认重载效果
    //会自动进行访问
    //此时p2是一个空指针，即保持的地址值为0
    //这个地址是不能访问的
    cout << p2 << endl;
    cout << "over" << endl;

}

int main(void){
    test0();
    return 0;
}
