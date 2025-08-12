#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//类名遵循大驼峰原则
struct Computer
{
/* public: */
    //成员函数名遵循小驼峰规则
    void setBrand(const char * brand)
    {
        strcpy(_brand,brand);
    }

    void setPrice(double price)
    {
        _price = price;
    }

    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

private:
    //数据成员名前面加上下划线
    char _brand[20];
    double _price;
};


void test0(){
    //内置类型的变量
    int a;
    a = 100;
    cout << a << endl;

    //自定义类型的对象
    Computer pc;
    pc.setBrand("Apple");
    pc.setPrice(14000);

    /* pc._price; */
    pc.print();
}

int main(void){
    test0();
    return 0;
}
