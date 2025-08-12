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

#if 0
    Computer(const Computer & rhs)
    : _brand(rhs._brand)//char * _brand = rhs._brand
    , _price(rhs._price)
    {
        cout << "Computer(const Computer &)" << endl;
    }
#endif

    Computer(const Computer & rhs)
    : _brand(new char[strlen(rhs._brand) + 1]())
    , _price(rhs._price)
    {
        strcpy(_brand,rhs._brand);
        cout << "Computer(const Computer &)" << endl;
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
    Computer pc2 = pc;
    pc2.print();
}

int main(void){
    test0();
    return 0;
}
