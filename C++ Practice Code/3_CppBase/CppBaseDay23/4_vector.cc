#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void test()
{
    vector<int> vec;
    vec.push_back(100);

    bool flag = true;
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << "  ";
        if(flag)
        {
            //此时执行push_back导致了底层发生了扩容，然后导致迭代器还
            //指向老的空间（迭代器失效了）
            //为了解决迭代器失效：可以更新迭代器
            vec.push_back(200);
            flag = false;
            it = vec.begin();//更新迭代器，让其与新空间产生联系
        }
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

