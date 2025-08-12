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

void test0()
{
    list<int> number = {1, 3, 5, 9, 7, 11};
    list<int> other = {2, 8, 6, 4, 10, 14};
    display(number);
    display(other);

    cout << endl <<endl;
    auto it = number.begin();
    /* it += 2; */
    ++it;
    ++it;
    cout << "*it = " << *it <<endl;
    number.splice(it, other);
    display(number);
    display(other);
}

void test()
{
    list<int> number = {1, 3, 5, 9, 7, 11};
    list<int> other = {2, 8, 6, 4, 10, 14};
    display(number);
    display(other);

    cout << endl <<endl;
    auto it = number.begin();
    /* it += 2; */
    ++it;
    ++it;
    cout << "*it = " << *it <<endl;
    auto oit = other.end();
    --oit;
    --oit;
    cout << "*oit = " << *oit <<endl;
    number.splice(it, other, oit);
    display(number);
    display(other);

    cout << endl << endl;
    auto oit1 = other.begin();
    cout << "*oit1 = " << *oit1 << endl;
    auto oit2 = other.end();
    --oit2;
    --oit2;
    cout << "*oit2 = " << *oit2 << endl;
    cout << "*it = " << *it <<endl;
    number.splice(it, other, oit1, oit2);
    display(number);
    display(other);

    cout << endl << "在同一个list中进行splice操作" << endl;
    it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << *it <<endl;

    auto it2 = number.end();
    --it2;
    --it2;
    cout << "*it2 = " << *it2 <<endl;
    number.splice(it, number, it2);
    display(number);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

