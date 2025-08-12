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

struct ComparePoint
{
    bool operator()( const int& lhs, const int& rhs ) const
    {
        cout << "struct ComparePoint" << endl;
        return lhs > rhs;
    }
};

void test()
{
    list<int> number = {1, 3, 3, 3, 5, 7, 9, 8, 3, 6};
    display(number);

    cout << endl << "list的reverse" << endl;
    number.reverse();
    display(number);

    cout << endl << "list的unique" << endl;
    number.unique();
    display(number);

    cout << endl << "list的sort" << endl;
    number.sort();//默认从小到大排序
    /* number.sort(std::less<int>()); */
    /* number.sort(std::greater<int>()); */
    /* number.sort(ComparePoint()); */
    display(number);

    cout << endl << "list的unique" << endl;
    number.unique();
    display(number);

    cout << endl << "list的merge" << endl;
    list<int> other = {13, 11, 2, 4, 10};
    other.sort();
    /* other.sort(std::greater<int>()); */
    display(other);
    number.merge(other);
    display(number);
    display(other);

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

