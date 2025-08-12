#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
    //设置品牌
    void setBrand(const char * brand);
    //设置价格
    void setPrice(double price);
    //打印信息
    void print();
private:
    char _brand[20];
    double _price;
};

void Computer::setBrand(const char * brand)
{
    strcpy(_brand,brand);
}

void Computer::setPrice(double price)
{
    _price = price;
}

void Computer::print(){
    cout << "brand:" << _brand << endl;
    cout << "price:" << _price << endl;
}

void test0(){
    Computer pc;
    pc.setBrand("Apple");
    pc.setPrice(14000);
    pc.print();
}

int main(void){
    test0();
    return 0;
}
