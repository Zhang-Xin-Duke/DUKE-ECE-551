#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::ostream_iterator;
using std::istream_iterator;
using std::copy;

void test()
{
    vector<int> vec;
    /* vec.reserve(10); */

    istream_iterator<int> isi(cin);

    //std::back_inserter函数的底层会调用容器vec的push_back
    copy(isi, istream_iterator<int>(), vec.begin());
    /* copy(isi, istream_iterator<int>(), std::back_inserter(vec)); */

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;
}
int main(int argc, char *argv[])
{
    test();
    return 0;
}

