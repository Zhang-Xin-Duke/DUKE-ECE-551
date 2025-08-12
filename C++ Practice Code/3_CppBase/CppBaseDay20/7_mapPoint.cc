#include <math.h>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;
using std::make_pair;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem.first << "  " << elem.second << endl;
    }
}

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
    }

    int getX() const
    {
        return _ix;
    }

    int getY() const
    {
        return _iy;
    }

    double getDistance()  const
    {
        return hypot(_ix, _iy);
    }

    ~Point()
    {

    }

    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
    /* friend bool operator<(const Point &lhs, const Point &rhs); */
    /* friend struct ComparePoint;//友元类 */
private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix
       << ", " << rhs._iy
       << ")";

    return os;
}

void test()
{
    map<string, Point> number = {
        {"beijing", Point(1, 2)},
        {"hello", Point(1, 2)},
        pair<string, Point>("nanjing", Point(3, 4)),
        pair<string, Point>("nanjing", Point(3, 4)),
        make_pair("dongjing", Point(4, 5)),
        make_pair("wangdao", Point(4, 5)),
    };
    display(number);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

