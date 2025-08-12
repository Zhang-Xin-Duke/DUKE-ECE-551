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


template <class T>
class RAII
{
public:
    RAII(T * data)
    : _data(data)
    {
        cout << "RAII(T*)" << endl;
    }

    ~RAII()
    {
        cout << "~RAII()" << endl;
        if(_data)
        {
            delete _data;
            _data = nullptr;
        }
    }

    //raii.operator->()->print();
    //raii->print();
    //raii->_ix;
    T * operator->()
    {
        return _data;
    }

    //*raii
    //raii.operator*()
    //(*raii).print();
    T & operator*()
    {
        return *_data;
    }

    //获取裸指针
    T * get() const
    {
        return _data;
    }

    void reset(T * data)
    {
        if(_data)
        {
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }

    RAII(const RAII &) = delete;
    RAII & operator=(const RAII &) = delete;
private:
    T * _data;
};

void test0(){
    /* //更推荐的做法 */
    /* RAII<int> raii(new int(20)); */

    int * p = new int(10);
    cout << p << endl;
    RAII<int> raii(p);
    cout << *raii << endl;
    cout << raii.get() << endl;

    /* delete p; */

    /* raii.reset(new int(20)); */
    /* cout << *raii << endl; */
    /* cout << raii.get() << endl; */
}

void test1()
{
    RAII<Point> ra(new Point(3,6));
    ra->print();
    (*ra).print();
    ra.reset(new Point(4,7));
    ra->print();
    (*ra).print();
}

int main(void){
    test1();
    return 0;
}
