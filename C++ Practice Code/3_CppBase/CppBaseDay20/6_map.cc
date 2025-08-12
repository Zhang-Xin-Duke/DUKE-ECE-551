#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;
using std::make_pair;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem.first << "  " << elem.second << endl;
    }
}

void test()
{
    //map的特征
    //1、存放key-value类型，key值是唯一的，不能重复，value值既可以重复
    //也可以不重复
    //2、默认情况下也会按照key进行升序排列
    //3、底层使用红黑树
    map<int, string> number = {
        //如何构建pair类型
        pair<int, string>(1, "hello"),
        pair<int, string>(3, "world"),
        make_pair(5, "beijing"),
        make_pair(5, "nanjing"),
        {4, "wuhan"},
        {6, "hello"},
    };
    display(number);

    cout << endl << "map的查找" << endl;
    size_t cnt = number.count(5);
    cout << "cnt = " << cnt << endl;

    map<int, string>::iterator it = number.find(2);
    if(it != number.end())
    {
        cout << "该元素存在map中 " << it->first 
             << "   " << it->second << endl;
    }
    else
    {
        cout << "查找失败，该元素不存在map中" << endl;
    }

    cout << endl << "map的插入操作" << endl;
    pair<map<int, string>::iterator, bool> ret = 
        number.insert({7, "shenzhen"});
    /* number.insert(pair<int, string>(7, "shenzhen")); */
    /* number.insert(make_pair(7, "shenzhen")); */
    if(ret.second)
    {
        cout << "插入成功 " << ret.first->first 
             << "   " << ret.first->second << endl;
    }
    else
    {
        cout << "插入失败，该元素存在map中" << endl;
    }
    display(number);

    cout << endl << "map的删除" << endl;
    it = number.begin();
    ++it;
    ++it;
    cout << it->first << "  " << it->second << endl << endl;
    number.erase(it);
    display(number);

    cout << endl << "map的下标" << endl;
    cout << "number[1] = " << number[1] << endl;//查找
    cout << "number[4] = " << number[4] << endl;//插入
    display(number);

    cout << endl << endl;
    //T &operator[](const Key &key)
    number[4] = "wangdao";//修改
    number[1] = "wangdao";
    display(number);

    /* const map<int, int> tmp = {{1, 2}}; */
    /* cout << tmp[1] <<endl; */
}


int main(int argc, char *argv[])
{
    test();
    return 0;
}

