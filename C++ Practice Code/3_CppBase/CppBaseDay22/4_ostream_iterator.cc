#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;
using std::copy;

void test()
{
    vector<int> vec = {1, 3, 5, 9, 8};
    ostream_iterator<int> osi(cout, "\n");

    copy(vec.begin(), vec.end(), osi);
    /* cout << 1 << "\n"; */
    /* cout << 3 << "\n"; */
    /* cout << 5 << "\n"; */
    /* cout << 9 << "\n"; */

    /* cout.operator<<(1); */
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

