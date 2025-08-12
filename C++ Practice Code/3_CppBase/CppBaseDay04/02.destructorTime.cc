#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
    /* Computer(){} */

    Computer(const char * brand,double price)
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
        /* cout << _brand << endl; */
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


Computer pc3("ASUS",5600);

void test0(){
    Computer pc("Dell",7000);

    Computer pc2("Lenovo",6000);

    static Computer pc4("hp",8000);

    /* int * pint = new int(2); */
    Computer * pp = new Computer("Huawei",7800);
    delete pp;
    pp = nullptr;
}

int main(void){
    test0();
    cout << "over" << endl;
    return 0;
}
