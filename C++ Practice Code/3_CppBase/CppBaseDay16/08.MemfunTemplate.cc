#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(double x,double y)
	: _x(x)
	, _y(y)
	{}

    template <class T = int>
    T convert();

    //虚函数与成员函数模板是冲突的
    //分别代表运行时多态和编译时多态
    template <class T,int z = 10>
    T add(T a) 
    {
        /* _x = 1; */
        /* return _x + _y + z + a; */
        return z + a + _test;
    }
private:
	double _x;
	double _y;
    static double _test; 
};
double Point::_test = 1;


template <class T>
T Point::convert()
{
    return (T)_x;
}

void test0(){
    Point pt(1.2,6.7);
    cout << pt.convert<int>() << endl;
    cout << pt.convert() << endl;

    cout << pt.add<double,12>(10) << endl;
    cout << pt.add(23) << endl;
}

int main(void){
    test0();
    return 0;
}
