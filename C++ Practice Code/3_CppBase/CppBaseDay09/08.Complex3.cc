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

    Complex & operator=(const Complex & rhs)
    {
        _real = rhs._real;
        _image = rhs._image;
        return *this;
    }

    //运算符重载的第三种形式
    //成员函数形式
    Complex operator+(const Complex & rhs)
    {
        return Complex(_real + rhs._real,
                       _image + rhs._image);
    }
private:
    int _real;
    int _image;
};


//赋值运算符只能用成员函数方式重载
/* Complex & operator=(Complex & lhs,const Complex & rhs); */

void test0(){
    int a = 1;
    int b = 2;
    cout << a + b << endl;

    Complex cx1(1,2);
    Complex cx2(3,4);

    cx1 = cx2;
    /* cx1.operator=(cx2); */

    /* cx1 + cx2; */
    //本质形式
    /* cx1.operator+(cx2); */
    Complex cx3 = cx1 + cx2;
    cx3.print();

}

int main(void){
    test0();
    return 0;
}
