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

void printCapacity(const vector<int> &con)
{
    cout << "size() = " << con.size() << endl;
    cout << "capacity() = " << con.capacity() << endl;
}

void test()
{
    vector<int> number = {1, 3, 5, 7, 9, 2, 4, 8, 6, 10};
    display(number);
    printCapacity(number);

    cout << endl <<  "在vector的尾部进行插入与删除" << endl;
    number.push_back(11);
    number.push_back(22);
    display(number);
    printCapacity(number);

    cout << endl <<  "在vector的任意位置进行插入" << endl;
    auto it = number.begin();
    it += 2;
    /* ++it; */
    /* ++it; */
    cout << "*it = " << *it << endl;
    number.insert(it, 123);
    display(number);
    printCapacity(number);
    cout << "*it = " << *it << endl;

    cout << endl << endl;
    it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    //vector的insert扩容原理
    //size() = t = 13, capacity() = n = 20,插入元素的个数m
    //1、m < n - t;此时不需要扩容
    //2、n - t < m < t;此时会按照2 * size()进行扩容
    //3、n - t < m < n; m > t此时会按照t + m进行扩容
    //4、n - t < m, m > n;此时也会按照t + m进行扩容
    number.insert(it, 50, 11);
    display(number);
    printCapacity(number);
    cout << "*it = " << *it << endl;

    cout << endl << endl;
    vector<int> vec = {111, 333, 555, 222};
    it = number.begin();
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    number.insert(it, vec.begin(), vec.end());
    display(number);
    printCapacity(number);
    cout << "*it = " << *it << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

