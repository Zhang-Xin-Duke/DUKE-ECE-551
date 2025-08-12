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
    class AutoRelease
    {
    public:
        AutoRelease(){}
        ~AutoRelease()
        {
            if(_pInstance){
                delete _pInstance;
                _pInstance = nullptr;
            }
            //保证了destroy函数一定会被自动调用
            //与第三种方式的思路一致
            /* destroy(); */
        }
    };

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
private:
    int _ix;
    int _iy;
    static Singleton * _pInstance;
    static AutoRelease _ar;
};
Singleton * Singleton::_pInstance = nullptr;
Singleton::AutoRelease Singleton::_ar;

void test0(){
    Singleton::getInstance()->init(100,200);
    Singleton::getInstance()->print();
    Singleton::getInstance()->init(10,20);
    Singleton::getInstance()->print();
    /* Singleton::destroy(); */
}

int main(void){
    test0();
    return 0;
}
