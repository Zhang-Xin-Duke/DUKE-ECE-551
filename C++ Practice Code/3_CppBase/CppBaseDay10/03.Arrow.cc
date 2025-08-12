#include <iostream>
using std::cout;
using std::endl;

class Data
{
public:
    Data()
    {
        cout << "Data()" << endl; 
    }
    ~Data()
    {
        cout << "~Data()" << endl;
    }

    int getData() const{ return _data; }
private:
    int _data = 10;
};

class MiddleLayer
{
public:
    MiddleLayer(Data * pd)
    : _pdata(pd)
    {
        cout << "MiddleLayer()" << endl;
    }

    ~MiddleLayer()
    {
        cout << "~MiddleLayer()" << endl;
        if(_pdata)
        {
            delete _pdata;
            _pdata = nullptr;
        }
    }

    Data * operator->()
    {
        return _pdata;
    }

    Data & operator*()
    {
        return *_pdata;
    }

private:
    Data * _pdata;
};


void test0(){
    Data * p1 = new Data();
    cout << p1->getData() << endl;
    cout << (*p1).getData() << endl;

    MiddleLayer ml(p1);
    //存在double free风险
    /* delete p1; */
    /* p1 = nullptr; */
}

void test1()
{
    Data * p1 = new Data();
    cout << p1->getData() << endl;
    cout << (*p1).getData() << endl;
    delete p1;
    p1 = nullptr;

    //智能指针的雏形
    //利用局部对象的生命周期管理堆空间资源
    //推荐写法
    MiddleLayer ml(new Data());

    //本质形式
    //ml调用成员函数operator->返回值为Data*
    //编译器再自动加上一个->
    /* cout << ml.operator->()->getData() << endl; */
    cout << ml->getData() << endl;

    //cx1 += cx2
    //cx1.operator+=(cx2)
    //++cx1;
    //cx1.operator++()

    //本质形式
    /* cout << ml.operator*().getData() << endl; */
    cout << (*ml).getData() << endl;
}


int main(void){
    test1();
    return 0;
}
