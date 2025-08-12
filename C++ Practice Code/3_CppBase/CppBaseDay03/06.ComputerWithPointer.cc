#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
    //char * pstr = new char[10]();
    Computer(const char * brand,double price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        strcpy(_brand,brand);
        cout << "Computer(const char *,double)" << endl;
    }

    /* void setBrand() */
    /* { */   
    /*     _brand[0] = 'W'; */
    /* } */

    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }
private:
    char * _brand;
    double _price;
};

void test1(){
    cout << sizeof(Computer) << endl;
    Computer pc("Dell",7000);
    pc.print();

    Computer pc2("Lenovo",6000);
    pc2.print();
}

int main(void){
    test1();
    return 0;
}
