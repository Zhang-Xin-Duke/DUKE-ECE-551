#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(long base = 1)
    : _base(base)
    {
        /* cout << "Base(long)" << endl; */
    }
    
    void print() const
    {
        cout << "_base:" << _base << endl;
        cout << "_data:" << _data << endl;
    }

/* protected: */
    long _base;
    long _data = 10;
};

class Derived
: public Base
{
public:
    Derived(long ba,long de)
    : Base(ba)
    , _derived(de)
    {
        /* cout << "Derived(long,long)" << endl; */
    }

    void print() const
    {
        cout << "_base:" << _base << endl;
        cout << "_derived:" << _derived << endl;
        cout << "_data:" << _data << endl;
    }
/* private: */
    long _derived;
    /* long _data = 100; */
    char _data = 'a';
};

void test1()
{
    Derived d1(4,5);
    //只需要派生类中声明了与基类中同名的成员
    //就可以对基类中这个成员构成隐藏
    d1.print();
    cout << endl;
    d1.Base::print();

}



#if 0
void test0(){
    cout << sizeof(Derived) << endl;
    Derived d1(7,8);
    /* d1.print(); */
    cout << d1._data << endl;
    cout << d1.Base::_data << endl;
}
#endif

int main(void){
    test1();
    return 0;
}
