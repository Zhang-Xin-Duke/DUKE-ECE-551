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

   
    MiddleLayer & operator->()
    {
        return *_pml;
    }


    //一层一层解引用
    //借助MiddleLayer之前已经完成了*的重载
    /* MiddleLayer & operator*() */
    /* { */
    /*     return *_pml; */
    /* } */

    //一步到位解引用
    Data & operator*()
    {
        /* return *((*_pml)._pdata);//需要友元的支持 */
        /* return *(*_pml);//需要MiddleLayer类对*的重载作为基础 */
        return (*_pml).operator*();
    }

private:
    MiddleLayer * _pml;
};

void test3()
{
    ThirdLayer tl(new MiddleLayer(new Data()));
    cout << tl->getData() << endl;


    //一层一层解引用
    /* cout << (*(*tl)).getData() << endl; */

    //一步到位解引用
    cout << (*tl).getData() << endl;
}

int main(void){
    test3();
    return 0;
}
