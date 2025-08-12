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

    //运算符重载的第一种形式
    //友元函数形式
    //定义一个operator+函数，并将这个函数声明为
    //Complex的友元函数
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
    int b = 2;
    cout << a + b << endl;

    Complex cx1(1,2);
    Complex cx2(3,4);
    /* Complex cx3 = add(cx1,cx2); */
    Complex cx3 = cx1 + cx2;
    //本质形式
    //Compledx cx3 = operator+(cx1,cx2);
    cx3.print();

}

int main(void){
    test0();
    return 0;
}
