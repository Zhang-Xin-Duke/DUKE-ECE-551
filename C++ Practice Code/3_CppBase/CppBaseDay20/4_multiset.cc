#include <iostream>
#include <set>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::multiset;
using std::vector;
using std::pair;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

void test()
{
    //multiset的特征
    //1、存放的是key类型，key值是不唯一的，可以重复
    //2、默认情况下，会按照key值进行升序排列
    //3、底层实现是红黑树
    /* multiset<int, std::greater<int>> number = {1, 4, 8, 7, 5, 4, 3, 7, 8, 9}; */
    multiset<int> number = {1, 4, 8, 4, 7, 5, 4, 3, 7, 8, 4, 9};
    display(number);

    cout << endl << "multiset的查找" << endl;
    size_t cnt = number.count(7);
    cout << "cnt = " << cnt << endl;

    multiset<int>::iterator it = number.find(6);
    if(it == number.end())
    {
        cout << "该元素不存在multiset中" << endl;
    }
    else
    {
        cout << "该元素存在multiset中 " << *it << endl;
    }

    cout << endl << "multiset的bound系列操作" << endl;
    auto it3 = number.lower_bound(4);
    cout << "*it3 = " << *it3 << endl;
    auto it4 = number.upper_bound(4);
    cout << "*it4 = " << *it4 << endl;
    while(it3 != it4)
    {
        cout << *it3 << "  ";
        ++it3;
    }
    cout << endl;

    pair<multiset<int>::iterator, multiset<int>::iterator> 
        ret = number.equal_range(4);
    while(ret.first != ret.second)
    {
        cout << *ret.first << "  ";
        ++ret.first;
    }
    cout << endl;

    cout << endl << "multiset的插入操作" << endl;
    number.insert(2);
    display(number);

    cout << endl << endl;
    vector<int> vec = {4, 10, 6, 7, 20, 3};
    number.insert(vec.begin(), vec.end());
    display(number);

    cout <<endl << endl;
    number.insert({11, 33, 22, 10});
    display(number);

    cout << endl << "multiset的删除操作" << endl;
    auto it2 = number.end();
    --it2;
    --it2;
    cout << "*it2 = " << *it2 <<endl;
    number.erase(it2);
    display(number);

    cout <<endl << endl;
    number.erase(10);
    display(number);

    cout << endl << "multiset的下标" << endl;
    /* cout << "number[1] = " << number[1] << endl; */

    cout <<endl << "使用迭代器修改multiset中的元素" << endl;
    it = number.begin();
    ++it;
    ++it;
    cout << "*it = " <<*it << endl;
    /* *it = 100;//error,不支持修改 */
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

