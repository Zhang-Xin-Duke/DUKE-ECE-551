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

    virtual void display() const
    {
        cout << "_base:" << _base << endl;
    }
protected:
    long _base;
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

    void display() const
    {
        cout << "_base:" << _base << endl;
        cout << "_derived:" << _derived << endl;
    }
private:
    long _derived;
};


void test0(){
    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    Derived d1(7,8);
    Base * pbase = &d1;
    pbase->display();

    cout << endl;
    Base base(10);
    Base * pb = &base;
    pb->display();
}

int main(void){
    test0();
    return 0;
}
