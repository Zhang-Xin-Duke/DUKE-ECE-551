#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

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
    list<int> number = {1, 3, 5, 7, 9, 8, 6, 4};
    display(number);
    cout << "size() = " << number.size() << endl;

    cout << endl;
    number.push_back(10);
    display(number);
    cout << "size() = " << number.size() << endl;

    cout << endl << "list的清空" << endl;
    number.clear();//清空元素
    cout << "size() = " << number.size() << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

