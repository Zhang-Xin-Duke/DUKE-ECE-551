#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_multiset;

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
    //unordered_multiset的特征
    //1、存放的是key类型，key值是不唯一的，可以重复
    //2、key值是没有顺序的
    //3、底层使用哈希表
    unordered_multiset<int> number = {8, 1, 7, 9, 6, 4, 5, 4, 3, 1, 5};
    display(number);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

