#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::for_each;
using std::vector;

void func(int &value)
{
    ++value;
    cout << value << "  ";
}

void test()
{
    vector<int> vec = {1, 4, 8, 6, 3, 4};
    for_each(vec.begin(), vec.end(), func);
    //lambda表达式---->匿名函数
    for_each(vec.begin(), vec.end(), [](int &value){
             ++value;
             cout << value << "  ";
             });
    cout << endl;

    for(auto &elem : vec)
    {
        cout << elem << "  ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

