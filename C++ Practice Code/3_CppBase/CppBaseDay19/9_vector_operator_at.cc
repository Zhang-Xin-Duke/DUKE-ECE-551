#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void test()
{
    vector<int> number;
    /* number[0]; */
    /* number[0] = 10; */
    number.at(0);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

