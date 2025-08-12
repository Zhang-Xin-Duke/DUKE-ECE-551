#include <iostream>
using std::cout;
using std::endl;

int count = 0;

class FunctionObject
{
public:
    //第一个()与operator连在一起作为函数名
    //第二个()代表参数列表
    void operator()()
    {
        ++_cnt;
        cout << "hello" << endl;
    }

    int operator()(int x)
    {
        ++_cnt;
        return x;
    }   

    double operator()(double x,double y)
    {
        ++_cnt;
        return x + y;
    }

    int getCount() const
    {
        return _cnt;
    }

private:
    int _cnt = 0;
};

void func()
{
    /* static int count = 0; */
    ++count;
    cout << "hello" << endl;
}

int func(int x)
{
    ++count;
    return x;
}

double func(double x,double y)
{
    ++count;
    return x + y;
}

void test0(){
    //希望让对象像函数一样调用
    FunctionObject fo;
    fo();
    /* fo.operator()(); */
    cout << fo(10) << endl;
    cout << fo(1.1,2.2) << endl;
    
    //函数对象相比于普通函数的优势
    //可以携带状态
    //对象同时还可以访问其他的成员
    /* fo._cnt = 0; */
    /* cout << "count:" << fo._cnt << endl; */
    cout << "count:" << fo.getCount() << endl;
    /* &(fo.getCount()); */


    cout << endl;
    func();
    func(1);
    func(2.4,8.9);
    /* count = 0; */
    cout << "count:" << count << endl;
}

int main(void){
    test0();
    return 0;
}
