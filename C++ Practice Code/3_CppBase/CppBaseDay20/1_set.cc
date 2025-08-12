#include <iostream>
#include <set>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::set;
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
    //set的特征
    //1、存放的是key类型，key值是唯一的，不能重复
    //2、默认情况下，会按照key值进行升序排列
    //3、底层实现是红黑树
    /* set<int, std::greater<int>> number = {1, 4, 8, 7, 5, 4, 3, 7, 8, 9}; */
    set<int> number = {1, 4, 8, 7, 5, 4, 3, 7, 8, 9};
    display(number);

    cout << endl << "set的查找" << endl;
    size_t cnt = number.count(7);
    cout << "cnt = " << cnt << endl;

    set<int>::iterator it = number.find(6);
    if(it == number.end())
    {
        cout << "该元素不存在set中" << endl;
    }
    else
    {
        cout << "该元素存在set中 " << *it << endl;
    }

    cout << endl << "set的插入操作" << endl;
    pair<set<int>::iterator, bool> ret = number.insert(2);
    if(ret.second)
    {
        cout << "插入成功 " << *ret.first <<endl;
    }
    else
    {
        cout << "插入失败，该元素存在set中" << endl;
    }
    display(number);

    cout << endl << endl;
    vector<int> vec = {4, 10, 6, 7, 20, 3};
    number.insert(vec.begin(), vec.end());
    display(number);

    cout <<endl << endl;
    number.insert({11, 33, 22, 10});
    display(number);

    cout << endl << "set的删除操作" << endl;
    auto it2 = number.end();
    --it2;
    --it2;
    cout << "*it2 = " << *it2 <<endl;
    number.erase(it2);
    display(number);

    cout <<endl << endl;
    number.erase(10);
    display(number);

    cout << endl << "set的下标" << endl;
    /* cout << "number[1] = " << number[1] << endl; */

    cout <<endl << "使用迭代器修改set中的元素" << endl;
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

