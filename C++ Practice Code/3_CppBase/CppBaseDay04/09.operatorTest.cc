#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
    Computer(const char * brand,double price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        strcpy(_brand,brand);
        cout << "Computer(const char *,double)" << endl;
    }

    Computer(const Computer & rhs)
    : _brand(new char[strlen(rhs._brand) + 1]())
    , _price(rhs._price)
    {
        strcpy(_brand,rhs._brand);
        cout << "Computer(const Computer &)" << endl;
    }

    //(1)
    //函数返回类型如果不是引用，而是对象
    //会发生一次不必要的复制
    //(2)
    //返回类型如果是void
    //那么无法进行连续赋值
    //(3)
    //参数设为引用可以避免发生一次不必要的复制
    //(4)
    //参数中的const可以保证不会利用形参改变实参
    //确保右操作数内容不会被修改
    //还有一个作用，能够接受右值属性对象的赋值
    Computer & operator=(const Computer & rhs)//pc = pc2;
    {
        cout << "Computer类的赋值运算符函数" << endl;
        if(this != &rhs)//1.判断自赋值情况
        {
            delete [] _brand;//2.回收左操作数的数据成员原本管理的堆空间资源
            _brand = new char[strlen(rhs._brand) + 1]();//3.进行深拷贝
            strcpy(_brand,rhs._brand);
            _price = rhs._price;//以及其他的数据成员的赋值
        }
        return *this;//4.返回本对象
    }
    

    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

    ~Computer()
    {
        cout << "~Computer()" << endl; 
        if(_brand)
        {
            delete [] _brand;
            _brand = nullptr;
        }
    }
private:
    char * _brand;
    double _price;
};


void test0(){
    int a = 1, b = 2, c = 3;
    a = b = c;

    Computer pc("Dell",7000);
    Computer pc2("Lenovo",5000);
    Computer pc3("Xiaomi",6000);
    pc = pc2 = pc3;
    /* pc.operator=(pc2); */
    pc.print();

    pc = Computer("Huawei",8000);



    /* cout << &pc << endl; */
    /* cout << &(pc = pc2) << endl; */
}

int main(void){
    test0();
    return 0;
}
