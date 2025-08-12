#include <iostream>
#include <sstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::istringstream;
using std::string;

void inputInt(istream & is,int & value)
{
    cout << "请输入整型数据" << endl;
    string word;
    while(is >> word,!is.eof())
    {
        auto it = word.begin();
        for( ;it != word.end(); ++it)
        {
            if(!isdigit(*it))
            {
                cout << "请输入整型数据" << endl;
                break;
            }
        }
        if(it == word.end())
        {
            istringstream iss(word);
            iss >> value;
            break;
        }
    }
}

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

#if 0
    //如果用成员函数的方式重载
    //那么能够实现的效果为cx1 << cout
    //与内置类型的使用形式不一致
    ostream & operator<<(ostream & os)
    {
        os << _real << " + "
          << _image << "i" << endl;
        return os;
    }
#endif

    friend
    ostream & operator<<(ostream & os,const Complex & rhs);
    friend
    istream & operator>>(istream & is,Complex & rhs);
private:
    int _real;
    int _image;
};

ostream & operator<<(ostream & os,const Complex & rhs)
{
    os << rhs._real << " + " << rhs._image << "i";
    return os;
}

istream & operator>>(istream & is,Complex & rhs)
{
    cout << "请输入实部" << endl;
    /* is >> rhs._real; */
    inputInt(is,rhs._real);
    cout << "请输入虚部" << endl;
    /* is >> rhs._image; */
    inputInt(is,rhs._image);
    return is;
}

void test0(){
    cout << 1 << endl;

    Complex cx1(1,2);
    //本质形式
    /* operator<<(cout,cx1); */
    cout << cx1 << endl;

    //ostream的拷贝构造被删除
    //ostream的移动构造是保护属性的
    /* cx1.operator<<(cout); */
    /* cx1 << cout; */
}

void test1()
{
    Complex cx1(1,2);
    cin >> cx1;
    cout << cx1 << endl;
}

int main(void){
    test1();
    return 0;
}
