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

    /* friend class ThirdLayer; */
private:
    Data * _pdata;
};

class ThirdLayer
{
public:
    ThirdLayer(MiddleLayer * pm)
    : _pml(pm)
    {
        cout << "ThirdLayer()" << endl;
    }

    ~ThirdLayer()
    {
        cout << "~ThirdLayer()" << endl;
        if(_pml)
        {
            delete _pml;
            _pml = nullptr;
        }
    }

    //方式一
    //借助友元声明
    /* Data * operator->() */
    /* { */
    /*     return (*_pml)._pdata; */
    /* } */

    //方式二
    //借助MiddleLayer之前已经完成了->的重载
    MiddleLayer & operator->()
    {
        return *_pml;
    }
private:
    MiddleLayer * _pml;
};

void test2()
{
    /* MiddleLayer ml(new Data()); */
    /* ThirdLayer tl(&ml); */

    /* MiddleLayer * pml = new MiddleLayer(new Data()); */
    /* ThirdLayer tl(pml); */
    /* delete pml;//仍然存在double free风险 */

    //推荐写法
    ThirdLayer tl(new MiddleLayer(new Data()));
}

void test3()
{
    ThirdLayer tl(new MiddleLayer(new Data()));
    
    //方式二的本质形式
    /* cout << ((tl.operator->()).operator->())->getData() << endl; */
    //方式一的本质形式
    /* cout << tl.operator->()->getData() << endl; */
    cout << tl->getData() << endl;

}

int main(void){
    test3();
    return 0;
}
