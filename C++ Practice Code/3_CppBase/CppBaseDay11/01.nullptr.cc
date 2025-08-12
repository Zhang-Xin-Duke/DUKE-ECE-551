#include <iostream>
using std::cout;
using std::endl;

class Bar{
public:
    void test0(){ cout << "Bar::test0()" << endl; }
    void test1(int x){ cout << "Bar::test1(): " << x << endl; }
    void test2(){ cout << "Bar::test2(): " << _data << endl; }
    static void test3()
    {
        cout << _da2 << endl;
    }

    int _data = 10;
    static int _da2;
};
int Bar::_da2 = 1;

void test0(){
    Bar * fp = nullptr;

    /* Bar b1; */
    /* Bar * fp = &b1; */
    //用指针fp调用非静态成员函数时
    //函数执行时加入的this指针
    //其实就是复制了fp所保存的地址值
    fp->test0();//ok
    fp->test1(3);//ok
    /* fp->test2(); //error */
    fp->test3();
}

int main(void){
    test0();
    return 0;
}
