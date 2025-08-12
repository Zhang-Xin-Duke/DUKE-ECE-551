#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

void test0()
{
    set<int> number = {1, 2, 3, 4, 5, 7, 9, 11, 14, 2, 4};
    display(number);

    //此种方法不能删除连续重复的奇数
    for(auto it = number.begin(); it != number.end(); ++it)
    {
        if(1 == *it % 2)
        {
            it = number.erase(it);
        }
    }
    display(number);
}

void test()
{
    set<int> number = {1, 2, 3, 4, 5, 7, 9, 11, 14, 2, 4};
    display(number);

    for(auto it = number.begin(); it != number.end(); )
    {
        if(1 == *it % 2)
        {
            it = number.erase(it);
        }
        else
        {
            ++it;
        }
    }
    display(number);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

