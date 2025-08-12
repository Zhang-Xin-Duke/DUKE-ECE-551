#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::shared_ptr;
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
void test0(){
    shared_ptr<int> sp(new int(67));
    shared_ptr<int> sp2 = sp;
    cout << *sp << endl;
    cout << *sp2 << endl;
    cout << sp.get() << endl;
    cout << sp2.get() << endl;
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;

    cout << endl;
    shared_ptr<int> sp3(new int(45));
    sp = sp3;
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << sp3.use_count() << endl;
}

void test1()
{
    shared_ptr<Point> sp(new Point(3,5));
    shared_ptr<Point> sp2 = sp;
    vector<shared_ptr<Point>> nums;
    nums.push_back(sp);
    nums[0]->print();
    cout << sp.use_count() << endl;

    cout << endl;
    //sp2将Point资源的管理权移交给vector的第二个元素
    nums.push_back(std::move(sp2));
    nums[1]->print();
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;

}

int main(void){
    test1();
    return 0;
}
