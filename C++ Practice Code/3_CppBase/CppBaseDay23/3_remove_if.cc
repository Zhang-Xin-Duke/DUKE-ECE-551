#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::remove_if;
using std::vector;
using std::for_each;
using std::ostream_iterator;
using std::copy;

bool func(int value)
{
    return value > 5;
}

void test()
{
    vector<int> vec = {1, 3, 5, 6, 7, 5, 4, 8, 3};
    for_each(vec.begin(), vec.end(), [](int &value){ 
             cout << value << "  "; 
             });
    cout << endl;

    cout << endl <<"执行remove_if操作"  <<endl;
    auto it = remove_if(vec.begin(), vec.end(), 
                        bind2nd(std::greater<int>(), 5));

    /* auto it = remove_if(vec.begin(), vec.end(), */ 
    /*                     bind1st(std::less<int>(), 5)); */

    //remove_if的第三个参数使用lambda表达式
    /* auto it = remove_if(vec.begin(), vec.end(), [](int value)->bool{ */
    /*                     return value > 5; */
    /*                     }); */

    //remove_if并不能一次将满足条件的元素删除，但是可以返回待删除元素的
    //首迭代器，再配合着容器的erase操作，就可以将不满足条件的元素删除
    /* auto it = remove_if(vec.begin(), vec.end(), func); */
    vec.erase(it, vec.end());
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;


}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

