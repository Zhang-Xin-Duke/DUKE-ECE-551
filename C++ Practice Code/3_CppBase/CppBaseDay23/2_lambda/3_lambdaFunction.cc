#include <iostream>
#include <string>
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::function;

void test()
{
    //void(const string &)
    function<void(const string &)> f = [](const string &name) {
        cout << "name = " << name << endl;
    };

    f("wangdao");
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

