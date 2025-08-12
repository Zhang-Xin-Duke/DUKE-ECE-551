#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::unordered_map;
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
    //unordered_map的特征
    //1、存放key-value类型，key值是唯一的，不能重复，value值既可以
    //重复，也可以不重复
    //2、key值是没有顺序的
    //3、底层采用的是哈希表
    unordered_map<int, string> number = {
        pair<int, string>(1, "hello"),
        pair<int, string>(3, "hello"),
        make_pair(2, "wangdao"),
        make_pair(2, "wangdao"),
        {4, "beijing"},
        {5, "shenzhen"}
    };
    display(number);

    cout << endl << "下标操作" << endl;
    cout << "number[1] = " << number[1] << endl;//查找
    cout << "number[6] = " << number[6] << endl;//插入
    display(number);

    cout << endl;
    number[6] = "wangdao";//修改
    display(number);

    /* const unordered_map<int, string> tmp = {{1, "wangdao"}}; */
    /* tmp[1];//error */
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

