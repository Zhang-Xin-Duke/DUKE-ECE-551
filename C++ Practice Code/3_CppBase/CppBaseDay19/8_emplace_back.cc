#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    Point(const Point &rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    ~Point()
    {

    }

    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
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
    vector<Point> number;
    /* Point pt(12, 2); */
    /* number.push_back(pt); */
    /* number.emplace_back(pt); */

    /* number.push_back(Point(1, 2)); */
    number.emplace_back(3, 2);

    for(auto &elem : number)
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

