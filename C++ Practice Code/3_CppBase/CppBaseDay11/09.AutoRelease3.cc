#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton * getInstance()
    {
        //当多个线程同时进入if语句时，
        //会导致Singleton对象被创建多个
        //但是只有一个Singleton对象的地址值被
        //_pInstance所保存
        //也就是只有这一对象能够被回收
        //其余全都泄露
        if(nullptr == _pInstance){
            atexit(destroy);
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
    
     
private:
    Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton & operator=(const Singleton &) = delete;
    
    static void destroy()
    {
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

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
private:
    int _ix;
    int _iy;
    static Singleton * _pInstance;
};

//饱汉式(懒汉式) —— 懒加载，在需要使用Singleton对象时才创建
/* Singleton * Singleton::_pInstance = nullptr; */

//饿汉式 —— 即使代码中不使用Singleton对象，
//也把这个堆对象创建出来
//即使是多线程环境，也能够确保这次getInstance的调用是第一次
Singleton * Singleton::_pInstance = Singleton::getInstance();

void test0(){
    Singleton::getInstance()->init(100,200);
    Singleton::getInstance()->print();
    Singleton::getInstance()->init(10,20);
    Singleton::getInstance()->print();
    /* Singleton::destroy(); */
    /* Singleton::destroy(); */
}

int main(void){
    test0();
    return 0;
}
