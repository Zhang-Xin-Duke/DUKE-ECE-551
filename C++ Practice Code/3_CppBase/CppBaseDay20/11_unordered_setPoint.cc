#include <iostream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_set;

template <typename Container>
void display(const Container &con)
{
    for(auto &elem : con)
    {
        cout << elem << "  ";
    }
    cout << endl;
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

//模板的特化去实现std::hash
namespace std
{

template <>
struct hash<Point>
{
    size_t operator()(const Point &rhs) const 
    {
        cout << "template <> struct hash" << endl;
        return ((rhs.getX() << 1) ^ (rhs.getY() << 2));
    }
};//end of struct hash

}//end of namespace std

//Hash模板参数的函数对象实现
struct HashPoint
{
    size_t operator()(const Point &rhs) const 
    {
        cout << "struct HashPoint" << endl;
        return ((rhs.getX() << 1) ^ (rhs.getY() << 2));
    }

};
 
//std::equal_to等价于operator==
bool operator==(const Point &lhs, const Point &rhs)
{
    cout << "bool operator==" << endl;
    return ((lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY()));
}

//std::equal_to针对Point进行特化
namespace std
{
template <>
struct equal_to<Point>
{
    bool operator()(const Point &lhs, const Point &rhs) const
    {
        cout << "template <> struct equal_to" << endl;
        return ((lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY()));
    }

};

}//end of namespace std

//针对KeyEqual进行函数对象的实现
struct EqualToPoint
{
    bool operator()(const Point &lhs, const Point &rhs) const
    {
        cout << "struct EqualToPoint" << endl;
        return ((lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY()));
    }

};
void test()
{
    /* unordered_set<Point> number = { */
    /* unordered_set<Point, HashPoint> number = { */
    /* unordered_set<Point, HashPoint, EqualToPoint> number = { */
    unordered_set<Point, std::hash<Point>, EqualToPoint> number = {
        Point(-1, 2),
        Point(1, 2),
        Point(-1, -2),
        Point(1, -2),
        Point(1, 2),
        Point(3, 2),
    };
    display(number);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

