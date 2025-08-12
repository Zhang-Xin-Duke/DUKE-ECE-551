#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::set;
using std::back_inserter;
using std::back_insert_iterator;
using std::front_inserter;
using std::front_insert_iterator;
using std::inserter;
using std::insert_iterator;
using std::ostream_iterator;
using std::copy;

void test()
{
    vector<int> vec = {1, 3, 9, 7, 5};
    list<int> lstNum = {2, 6, 8, 4, 10};

    //将list中的数据插入到vector尾部
    copy(lstNum.begin(), lstNum.end(), back_inserter(vec));
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

    //将vector中的数据插入到list头部
    cout << endl << endl;
    copy(vec.begin(), vec.end(), front_inserter(lstNum));
    copy(lstNum.begin(), lstNum.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;
    
    /* //将list中的数据插入到vector头部 */

    //将vector中的元素插入到set中
    cout << endl << endl;
    set<int> setNum = {1, 4, 9, 10, 14, 11};
    auto it = setNum.begin();
    copy(vec.begin(), vec.end(), inserter(setNum, it));
    copy(setNum.begin(), setNum.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

