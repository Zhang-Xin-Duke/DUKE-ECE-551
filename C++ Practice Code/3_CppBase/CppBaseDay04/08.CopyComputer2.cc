#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
    Computer(const char * brand,double price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        strcpy(_brand,brand);
        cout << "Computer(const char *,double)" << endl;
    }

    Computer(const Computer & rhs)
    : _brand(new char[strlen(rhs._brand) + 1]())
    , _price(rhs._price)
    {
        strcpy(_brand,rhs._brand);
        cout << "Computer(const Computer &)" << endl;
    }

#if 0
    //pc = pc2;
    //pc.operator=(pc2);
    Computer & operator=(const Computer & rhs)
    {
        cout << "Computer类的赋值运算符函数" << endl;
        this->_brand = rhs._brand;
        this->_price = rhs._price;
        return *this;
    }
#endif

    //pc = pc2;
    Computer & operator=(const Computer & rhs)
    {
        cout << "Computer类的赋值运算符函数" << endl;
        if(this != &rhs)//1.判断自赋值情况
        {
            delete [] _brand;//2.回收左操作数的数据成员原本管理的堆空间资源
            _brand = new char[strlen(rhs._brand) + 1]();//3.进行深拷贝
            strcpy(_brand,rhs._brand);
            _price = rhs._price;//以及其他的数据成员的赋值
        }
        return *this;//4.返回本对象
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
    Computer pc2("Lenovo",5000);
    pc = pc2;
    pc.print();

    //自赋值操作
    pc2 = pc2;
    pc2.print();
}

int main(void){
    test0();
    return 0;
}
