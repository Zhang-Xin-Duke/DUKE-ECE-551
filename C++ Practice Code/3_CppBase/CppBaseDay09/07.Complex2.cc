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
    
    int getReal() const
    { return _real; }

    int getImage() const
    { return _image; }

private:
    int _real;
    int _image;
};

//运算符重载的第二种方式
//定义一个普通函数(operator+)
//利用公有的get函数间接获取Complex的私有成员的内容
Complex operator+(const Complex & lhs,const Complex & rhs)
{
    return Complex(lhs.getReal() + rhs.getReal(),
                   lhs.getImage() + rhs.getImage());
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
    /* Complex cx4 = operator+(cx1,cx2); */
    cx3.print();

}

int main(void){
    test0();
    return 0;
}
