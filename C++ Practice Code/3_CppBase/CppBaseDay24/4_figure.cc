#include <math.h>
#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::function;
using std::bind;

//面向对象的方式：纯虚函数 + 继承
//基于对象的方式: std::bind + std::function
//
//C语言中回调函数的使用会借助函数指针，但是在C++11中还可以使用
//std::bind + std::function

class Figure
{
public:
    using DisplayCallback = function<void()>;
    using AreaCallback = function<double()>;

    /* void setDisplayCallback(const DisplayCallback &cb) */
    /* { */
    /*     _displayCallback = cb; */
    /* } */

    void setDisplayCallback(DisplayCallback &&cb)
    {
        _displayCallback = std::move(cb);
    }

    void setAreaCallback(AreaCallback &&cb)
    {
        _areaCallback = std::move(cb);
    }

    void handleDisplayCallback() const
    {
        if(_displayCallback)
        {
            _displayCallback();
        }
    }

    double handleAreaCallback() const
    {
        if(_areaCallback)
        {
            return _areaCallback();
        }
        else
        {
            return 0.0;
        }
    }

    DisplayCallback _displayCallback;
    AreaCallback _areaCallback;
    /* //纯虚函数 */
    /* virtual void display() const = 0; */
    /* virtual double area() const = 0; */
};

class Rectangle
{
public:
    Rectangle(double length = 0, double width = 0)
    : _length(length)
    , _width(width)
    {
        cout << "Rectangle(double = 0, double = 0)" << endl;
    }

    void display(int x) const 
    {
        cout << "Rectangle";
    }

    double area() const 
    {
        return _length * _width;
    }

    ~Rectangle()
    {
        cout << "~Rectangle()" << endl;
    }
private:
    double _length;
    double _width;
};

class Circle
{
public:
    Circle(double radius = 0)
    : _radius(radius)
    {
        cout << "Circle(double = 0)" << endl;
    }

    void print() const 
    {
        cout << "Circle";
    }

    double printArea() const 
    {
        return 3.14 * _radius *_radius;;
    }

    ~Circle()
    {
        cout << "~Circle()" << endl;
    }

private:
    double _radius;
};

class Triangle
{
public:
    Triangle(double a = 0, double b = 0, double c = 0)
    : _a(a)
    , _b(b)
    , _c(c)
    {
        cout << "Triangle(double = 0, double = 0, double = 0)" << endl;
    }

    void show() const 
    {
        cout << "Triangle";
    }

    double showArea() const 
    {
        //海伦公式
        double tmp = (_a + _b + _c)/2;

        return sqrt(tmp * (tmp - _a) * (tmp - _b) * (tmp - _c));
    }

    ~Triangle()
    {
        cout << "~Triangle()" << endl;
    }
private:
    double _a;
    double _b;
    double _c;
};

void func(const Figure &fig)
{
    fig.handleDisplayCallback();
    cout << "的面积 : " << fig.handleAreaCallback() << endl;
}

int main(int argc, char **argv)
{
    Rectangle rectangle(10, 20);
    Circle circle(10);
    Triangle triangle(3, 4, 5);

    cout << endl;
    Figure fig;
    /* function<void()> f = bind(&Rectangle::display, &rectangle, 10); */
    /* fig.setDisplayCallback(std::move(f)); */
    fig.setDisplayCallback(bind(&Rectangle::display, &rectangle, 10));
    fig.setAreaCallback(bind(&Rectangle::area, &rectangle));
    func(fig);

    fig.setDisplayCallback(bind(&Circle::print, &circle));
    fig.setAreaCallback(bind(&Circle::printArea, &circle));
    func(fig);

    fig.setDisplayCallback(bind(&Triangle::show, &triangle));
    fig.setAreaCallback(bind(&Triangle::showArea, &triangle));
    func(fig);

    return 0;
}
