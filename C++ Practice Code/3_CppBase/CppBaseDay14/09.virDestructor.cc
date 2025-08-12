#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base()
    : _pbase(new int(10))
    {
        cout << "Base()" << endl;
    }

    virtual void display() const
    {
        cout << "Base::display " << *_pbase << endl;
    }

    virtual ~Base()
    {
        cout << "~Base()" << endl; 
        if(_pbase)
        {
            delete _pbase;
            _pbase = nullptr;
        }
    }

private:
    int * _pbase;
};

class Derived
: public Base
{
public:
    Derived()
    : _pderived(new int(20))
    {
        cout << "Derived()" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl; 
        if(_pderived)
        {
            delete _pderived;
            _pderived = nullptr;
        }
    }

    virtual void display() const
    {
        cout << "Derived::display " << *_pderived << endl;
    }

private:
    int * _pderived;
};

void test0(){
    /* Derived d1; */
    /* Base * pb = &d1; */
    /* pb->display(); */

    Base * pb = new Derived();
    pb->display();
    delete pb;

    /* Derived * pd = new Derived(); */
    /* pd->display(); */
    /* delete pd; */
}

int main(void){
    test0();
    return 0;
}
