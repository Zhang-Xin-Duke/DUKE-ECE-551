#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

int totalPrice = 0;

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

    //pc = pc2;
    Computer & operator=(const Computer & rhs)
    {
        cout << "Computer类的赋值运算符函数" << endl;
        if(this != &rhs)//1.判断自赋值情况
        {
            _totalPrice -= _price;
            delete [] _brand;//2.回收左操作数的数据成员原本管理的堆空间资源
            _brand = new char[strlen(rhs._brand) + 1]();//3.进行深拷贝
            strcpy(_brand,rhs._brand);
            _price = rhs._price;//以及其他的数据成员的赋值
            _totalPrice += _price;
        }
        return *this;//4.返回本对象
    }

    void print(){
        cout << "brand:" << this->_brand << endl;
        cout << "price:" << this->_price << endl;
        /* cout << "totalPrice:" << _totalPrice << endl; */
    }

    static void printTotalPrice()
    {
        //静态成员函数没有this指针
        //所以无法直接通过非静态成员的名字来访问这些成员
        //当然，如果接受了对象作为参数
        //rhs._price这样访问是可以的
        /* cout << "price:" << _price << endl; */
        cout << "totalPrice:" << _totalPrice << endl;

        //四大金刚可以在静态成员函数中调用
        //但是四大金刚不能设为静态成员函数
        /* Computer pc("ABC",2000); */
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

    /* pc.printTotalPrice(); */
    /* pc2.printTotalPrice(); */
    //静态成员函数可以通过类名 + 作用域限定符的方式访问
    Computer::printTotalPrice();

    //静态数据成员可以通过类名 + 作用域限定符的方式访问
    
    /* Computer::_totalPrice = 0; */
    /* cout << pc._totalPrice << endl; */
    /* cout << pc2._totalPrice << endl; */
    /* cout << Computer::_totalPrice << endl; */
    /* cout << Computer::_price << endl; */

    /* totalPrice = 0; */
    /* cout << totalPrice << endl; */
}

int main(void){
    test0();
    return 0;
}
