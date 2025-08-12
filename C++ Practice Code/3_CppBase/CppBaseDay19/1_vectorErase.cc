#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void test0()
{
    vector<int> number = {1, 3, 5, 5, 5, 5, 7, 5, 5, 9};
    for(auto it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;

    //将值为5的元素全部删除
    //结果：不能删除连续重复的元素
    for(auto it = number.begin(); it != number.end(); ++it)
    {
        if(5 == *it)
        {
            number.erase(it);
        }
    }

    //删除之后的元素进行遍历
    for(auto it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;
    
}

void test()
{
    vector<int> number = {1, 3, 5, 5, 5, 5, 7, 5, 5, 9};
    for(auto it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;

    //将值为5的元素全部删除
    for(auto it = number.begin(); it != number.end(); )
    {
        if(5 == *it)
        {
            it = number.erase(it);
        }
        else
        {
            ++it;
        }
    }

    //删除之后的元素进行遍历
    for(auto it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;
    
}
int main(int argc, char *argv[])
{
    test();
    return 0;
}

