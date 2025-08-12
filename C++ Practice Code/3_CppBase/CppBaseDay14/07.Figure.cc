#include <math.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Figure{
public:
    virtual string getName() const = 0;
    virtual double getArea() const = 0;
};

void display(Figure & fig)
{
    cout << fig.getName()
        << "的面积是："
        << fig.getArea() << endl;
}

class Rectangle
: public Figure
{
public:
    Rectangle(double len,double wid)
    : _length(len)
    , _width(wid)
    {}

    string getName() const override
    {
        return "矩形";
    }

    double getArea() const override
    {
        return _length * _width;
    }

private:
    double _length;
    double _width;
};

class Circle
: public Figure
{
public:
    Circle(double rad)
    : _radius(rad)
    {}
 
    string getName() const override
    {
        return "圆形";
    }

    double getArea() const override
    {
        return PI * _radius * _radius; 
    }

private:
    static constexpr double PI = 3.14;
    double _radius;
    /* static const double PI; */
};
/* const double Circle::PI = 3.14; */

class Triangle
: public Figure
{
public:
    Triangle(double a,double b,double c)
    : _x(a)
    , _y(b)
    , _z(c)
    {}
  
    string getName() const override
    {
        return "三角形";
    }

    double getArea() const override
    {
        double c = (_x + _y + _z)/2;
        return sqrt(c * (c - _x) * (c - _y) * (c - _z));
    }
private:
    double _x;
    double _y;
    double _z;
};


void test0(){
    /* Figure fg; */
    Rectangle re(7,8);
    Circle cl(2);
    Triangle tr(5,12,13);
    display(re);
    display(cl);
    display(tr);
}

int main(void){
    test0();
    return 0;
}
