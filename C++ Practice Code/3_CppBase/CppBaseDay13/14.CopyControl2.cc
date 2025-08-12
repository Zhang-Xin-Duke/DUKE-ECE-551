#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(long base)
    : _base(base)
    {
        /* cout << "Base(long)" << endl; */
    }
protected:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long ba,long de,const char * pderived)
    : Base(ba)
    , _derived(de)
    , _pderived(new char[strlen(pderived) + 1]())
    {
        strcpy(_pderived,pderived);
        /* cout << "Derived(long,long)" << endl; */
    }

    Derived(const Derived & rhs)
    : Base(rhs) //显式调用Base的拷贝构造
    , _derived(rhs._derived)
    , _pderived(new char[strlen(rhs._pderived) + 1]())
    {
        cout << "Derived的拷贝构造" << endl;
        strcpy(_pderived,rhs._pderived);
    }

    Derived & operator=(const Derived & rhs)
    {
        cout << "Derived的赋值运算符函数" << endl;
        if(this != &rhs){
            Base::operator=(rhs);//显式调用Base的赋值运算符函数
            delete [] _pderived;
            _pderived = new char[strlen(rhs._pderived) + 1]();
            strcpy(_pderived,rhs._pderived);
            _derived = rhs._derived;
        }
        return *this;
    }

    ~Derived()
    {
        if(_pderived){
            delete [] _pderived;
            _pderived = nullptr;
        }
    }

    void print() const
    {
        cout << "_base:" << _base << endl;
        cout << "_derived:" << _derived << endl;
        cout << "_pderived:" << _pderived << endl;
    }
private:
    long _derived;
    char * _pderived;
};


void test0(){
    Derived d1(7,8,"beijing");
    Derived d2 = d1;
    d2.print();

    Derived d3(3,5,"shanghai");
    d3 = d2;
    d3.print();
}

int main(void){
    test0();
    return 0;
}
