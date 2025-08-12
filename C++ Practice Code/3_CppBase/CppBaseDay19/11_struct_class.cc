#include <iostream>

using std::cout;
using std::endl;

struct Base
/* class Base */
{
    void print()
    {
        cout << "void Base::print()" << endl;
    }
};

struct Derived
/* class Derived */
: Base
{

};

void test()
{
    Derived d;
    d.print();
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

