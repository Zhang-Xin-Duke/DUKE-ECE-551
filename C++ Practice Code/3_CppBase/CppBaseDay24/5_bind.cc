#include <iostream>
#include <functional>
#include <string>

using std::cout;
using std::endl;
using std::bind;
using std::function;
using std::string;

class Example
{
public:
    int add(int x, int y)
    {
        cout << "int Example::add(int, int)" << endl;
        return x + y;
    }
};

void test()
{
    Example ex;
    using namespace std::placeholders;
    function<int(Example *)> f = bind(&Example::add, _1, 10, 20);
    cout << "f(&ex) = " << f(&ex) << endl;

    cout << endl;
    function<int(Example )> f2 = bind(&Example::add, _1, 100, 200);
    cout << "f2(ex) = " << f2(ex) << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

