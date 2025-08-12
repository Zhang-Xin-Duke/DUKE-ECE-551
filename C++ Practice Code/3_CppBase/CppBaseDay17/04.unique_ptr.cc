#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

class Point
{
public:
    Point(double x,double y)
    : _x(x)
    , _y(y)
    {}

    void print() const
    {
        cout << "(" << _x
            << "," << _y
            << ")" << endl;
    }
private:
    double _x;
    double _y;
};

void test1()
{
    unique_ptr<Point> up(new Point(3,5));
    unique_ptr<Point> up2(new Point(4,7));
    unique_ptr<Point> up3(new Point(8,9));
    vector<unique_ptr<Point>> nums;

    //需要使用移动语义
    //将这个临时对象通过移动构造产生的副本
    //作为vector的元素
    nums.push_back(unique_ptr<Point>(new Point(4,6)));
    nums[0]->print();
    //移交管理权
    nums.push_back(std::move(up));
    nums[1]->print();
    /* up->print();//error */

    up.reset(new Point(6,6));
    up->print();
} 


void test0(){
    unique_ptr<int> up(new int(34));
    cout << *up << endl;
    cout << up.get() << endl;

    //语法层面禁止了复制和赋值
    /* unique_ptr<int> up2 = up; */
    unique_ptr<int> up2(new int(24));
    /* up = up2; */
}

int main(void){
    test1();
    return 0;
}
