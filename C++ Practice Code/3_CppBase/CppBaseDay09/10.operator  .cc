#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
    Complex(int real,int image)
    : _real(real)
    , _image(image)
    {}

    void print() const
    {
        cout << _real << " + "
            << _image << "i" << endl;
    }

    Complex & operator+=(const Complex & rhs)
    {
        _real += rhs._real;
        _image += rhs._image;
        return *this;
    }
    
    Complex & operator++()
    {
        cout << "前置++" << endl;
        ++_real;
        ++_image;
        return *this;
    }

    //后置++的重载函数在参数列表中加上一个int
    //和前置++作出区分
    Complex operator++(int)
    {
        cout << "后置++" << endl;
        Complex temp = *this;
        ++_real;
        ++_image;
        return temp;
    }


    friend
    Complex operator+(const Complex & lhs,const Complex & rhs);
private:
    int _real;
    int _image;
};

Complex operator+(const Complex & lhs,const Complex & rhs)
{
    return Complex(lhs._real + rhs._real,
                   lhs._image + rhs._image);
}


void test0(){
    int a = 1;
    cout << &a << endl;
    cout << &(++a) << endl; //a = 2
    //a++的返回值是2(临时值，改变之前的副本)
    //a = 3
    /* cout << &(a++) << endl; */
    cout << a++ << endl;
    cout << a << endl;
}

void test1()
{
    Complex cx1(1,2);
    cout << &cx1 << endl;
    //本质形式
    //cx1.operator++();
    cout << &(++cx1) << endl;

    /* cx1.operator++(100); */
    (cx1++).print();
    cx1.print();
}

int main(void){
    test1();
    return 0;
}
