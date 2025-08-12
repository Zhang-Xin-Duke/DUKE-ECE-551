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

//cx1 + 10
Complex operator+(const Complex & lhs,int rhs)
{}


/* int operator+(int lhs,int rhs) */
/* { */
/*     return lhs - rhs; */
/* } */


void test0(){
    int a = 1;
    int b = 2;
    cout << a + b << endl;
    cout << &(a += b) << endl;
    cout << &a << endl;

    Complex cx1(1,2);
    Complex cx2(3,4);
    //cx1.operator+=(cx2);
    cout << &(cx1 += cx2) << endl;
    cout << &cx1 << endl;
    cx1.print();

}

int main(void){
    test0();
    return 0;
}
