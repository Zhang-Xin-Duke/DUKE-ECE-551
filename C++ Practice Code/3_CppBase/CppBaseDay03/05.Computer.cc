#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
    Computer(const char * brand,double price)
    /* : _brand(brand) //char _brand[20] = brand; */
    /* : _brand{'D','e','l','l','\0'} */
    : _brand{}
    , _price(price) //double _price = price;
    {
        strcpy(_brand,brand);
    }

    /* void setBrand(const char * brand) */
    /* { */
    /*     strcpy(_brand,brand); */
    /* } */

    /* void setPrice(double price) */
    /* { */
    /*     _price = price; */
    /* } */

    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }
private:
    char _brand[20];
    double _price;
};

void test1(){
    cout << sizeof(Computer) << endl;
    Computer pc("Dell",7000);
    pc.print();
}

#if 0
void test0(){
    int a;
    a = 100;
    cout << a << endl;

    int b = 1;
    cout << b << endl;

    Computer pc;
    pc.setBrand("Apple");
    pc.setPrice(14000);
    pc.print();
}
#endif

int main(void){
    test1();
    return 0;
}
