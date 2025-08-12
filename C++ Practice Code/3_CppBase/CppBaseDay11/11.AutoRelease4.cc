#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton * getInstance()
    {
        pthread_once(&_once,&init_r);
        return _pInstance;
    }


    /* void func() */
    /* { */
    /*     cout << "hello" << endl; */
    /* } */

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

    static void init_r()
    {
        _pInstance = new Singleton(1,2);
        atexit(destroy);
    }

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
    static pthread_once_t _once;
};
Singleton * Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

void test0(){
    Singleton::getInstance()->init(100,200);
    Singleton::getInstance()->print();
    Singleton::getInstance()->init(10,20);
    Singleton::getInstance()->print();

    //destroy一旦被手动调用
    //后续再通过getInstance是不能创建出Singleton对象的
    /* Singleton::destroy(); */
    /* Singleton::getInstance()->init(10,20); */
    /* Singleton::getInstance()->print(); */
    /* Singleton::getInstance()->func(); */

    //如果手动调用init_r
    //那么会绕过pthread_once的管理，导致内存泄露
    /* Singleton::init_r(); */
    /* Singleton::init_r(); */
    /* Singleton::init_r(); */

}

int main(void){
    test0();
    return 0;
}
