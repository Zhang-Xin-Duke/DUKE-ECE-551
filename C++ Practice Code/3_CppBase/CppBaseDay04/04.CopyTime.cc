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
    Computer pc("Dell",7000);
    //拷贝构造的第一种调用时机
    //利用一个已存在的对象以复制的方式初始化一个新对象
    Computer pc2 = pc;
    pc2.print();
}

//拷贝构造的第二种调用时机
//函数的形参和实参是同一类型对象
//用实参初始化形参时实际上会发生复制
//类似于值传递
/* void func(Computer pc) */
/* { */
/*     pc.print(); */
/* } */

//为了避免不必要的开销
//可以将函数形参设为引用
void func(Computer & pc)
{
    pc.print();
}

void test1(){
    Computer pc1("Apple",20000);
    func(pc1);
}


//拷贝构造的第三种调用时机
//当函数返回值为对象时
//执行return语句会触发拷贝构造
/* Computer func2(){ */
/*     Computer ppc("Xiaomi",6000); */
/*     return ppc; */
/* } */

//注意返回的引用所绑定的本体生命周期比函数更长
Computer & func2(){
    static Computer ppc("Xiaomi",6000);
    return ppc;
}

void test2(){
    //func2的返回值是ppc的一个副本
    //生命周期仅在当前行
    /* func2().print(); */

    //返回值是ppc的一个引用
    func2().print();
}

int main(void){
    test2();
    return 0;
}
