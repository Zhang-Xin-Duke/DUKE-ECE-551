#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

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
    vector<int> number = {1, 3, 5, 7, 9, 8, 6, 4};
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;

    cout << endl;
    number.push_back(10);
    display(number);
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;

    cout << endl << "vector的清空" << endl;
    number.clear();//清空元素
    number.shrink_to_fit();//回收多余的空间
    cout << "size() = " << number.size() << endl;
    cout << "capacity() = " << number.capacity() << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

