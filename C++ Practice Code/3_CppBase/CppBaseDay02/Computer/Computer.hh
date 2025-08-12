#ifndef __Computer_HH__
#define __Computer_HH__

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

inline
void Computer::setBrand(const char * brand)
{
    strcpy(_brand,brand);
}

inline
void Computer::setPrice(double price)
{
    _price = price;
}

inline
void Computer::print(){
    cout << "brand:" << _brand << endl;
    cout << "price:" << _price << endl;
}



#endif
