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
        _totalPrice += _price;
        strcpy(_brand,brand);
        cout << "Computer(const char *,double)" << endl;
    }

    Computer(const Computer & rhs)
    : _brand(new char[strlen(rhs._brand) + 1]())
    , _price(rhs._price)
    {
        _totalPrice += _price;
        strcpy(_brand,rhs._brand);
        cout << "Computer(const Computer &)" << endl;
    }

    Computer & operator=(const Computer & rhs)
    {
        cout << "Computer类的赋值运算符函数" << endl;
        if(this != &rhs)
        {
            _totalPrice -= _price;
            delete [] _brand;
            _brand = new char[strlen(rhs._brand) + 1]();
            strcpy(_brand,rhs._brand);
            _price = rhs._price;
            _totalPrice += _price;
        }
        return *this;
    }

    //const成员函数中不能修改对象的数据成员
    //const Computer * const this
    void print() const{
        //人为避免
        /* _brand[0] = 'X'; */

        //const成员函数限制的是如下的修改
        /* _brand = nullptr; */
        /* _price = 0; */
        cout << "brand:" << this->_brand << endl;
        cout << "price:" << this->_price << endl;
    }

    static void printTotalPrice()
    {
        cout << "totalPrice:" << _totalPrice << endl;
    }

    ~Computer()
    {
        cout << "~Computer()" << endl; 
        if(_brand)
        {
            _totalPrice -= _price;
            delete [] _brand;
            _brand = nullptr;
        }
    }
private:
    char * _brand;
    double _price;
    static double _totalPrice;
};
double Computer::_totalPrice = 0;

void test0(){
    cout << sizeof(Computer) << endl;
    Computer pc("Dell",7000);
    Computer pc2("Lenovo",5000);
    Computer pc3("Xiaomi",6000);
    pc.print();
}

int main(void){
    test0();
    return 0;
}
