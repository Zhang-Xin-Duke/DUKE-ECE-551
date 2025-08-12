#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton * getInstance()
    {
        if(nullptr == _pInstance){
            _pInstance = new Singleton(1,2);
        }
        return _pInstance;
    }

    void init(int x,int y)
    {
        _ix = x;
        _iy = y;
    }
 
    void print() const
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
    
    /* static void destroy() */
    /* { */
    /*     if(_pInstance){ */
    /*         delete _pInstance; */
    /*         _pInstance = nullptr; */
    /*     } */
    /* } */
  
private:
    Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton & operator=(const Singleton &) = delete;

    Singleton(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Singleton(int,int)" << endl;
    }
    
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }
    friend class AutoRelease;
private:
    int _ix;
    int _iy;
    static Singleton * _pInstance;
};
Singleton * Singleton::_pInstance = nullptr;

class AutoRelease
{
public:
    AutoRelease(Singleton * p)
    : _p(p)
    {}

    ~AutoRelease()
    {
        if(_p)
        {
            delete _p;
            _p = nullptr;
        }
    }
private:
    Singleton * _p;
};


#if 0
void test0(){
    Singleton * p1 = Singleton::getInstance();
    p1->init(100,200);
    p1->print();

    //如果是一个普通的Singeleton*指针
    //不能在Singleton类外调用私有的析构函数
    /* delete p1; */
    /* Singleton::destroy(); */
}
#endif

void test1()
{
    //仍然要注意不能使用多个AutoRelease对象管理堆上的单例对象
    //否则也会发生double free问题
    AutoRelease ar(Singleton::getInstance());
    /* AutoRelease ar2(Singleton::getInstance()); */

    Singleton::getInstance()->init(100,200);
    Singleton::getInstance()->print();
    Singleton::getInstance()->init(10,20);
    Singleton::getInstance()->print();
    //不能手动调用destroy，会导致double free
    /* Singleton::destroy(); */
}

int main(void){
    test1();
    return 0;
}
