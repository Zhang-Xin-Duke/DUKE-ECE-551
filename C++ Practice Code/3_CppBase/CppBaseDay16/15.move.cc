#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
    String()
    : _pstr(new char[1]())
    {
        cout << "String()" << endl;
    }

    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    //移动构造
    String(String && rhs)
    : _pstr(rhs._pstr)
    {
        cout << "String的移动构造" << endl;
        rhs._pstr = nullptr;
    }


    String(const String & rhs)
    : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    //移动赋值函数
    String & operator=(String && rhs)
    {
        cout << "移动赋值函数" << endl;
        if(this != &rhs)
        {
            delete [] _pstr;
            _pstr = rhs._pstr;
            rhs._pstr = nullptr;
        }
        return *this;
    }


    String & operator=(const String & rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        if(this != &rhs)
        {
             delete [] _pstr;  
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }

    size_t length() const
    {
        size_t len = 0;
        if(_pstr)
        {
            len = strlen(_pstr);
        }

        return len;

    }

    const char * c_str() const
    {
        if(_pstr)
        {
            return _pstr;
        }
        else
        {
            return nullptr;
        }
    }


    ~String()
    {
        cout << "~String()" << endl;
        if(_pstr)
        {
            delete [] _pstr;
            _pstr = nullptr;
        }
    }

    void print() const
    {
        if(_pstr)
        {
            cout << "_pstr = " << _pstr << endl;
        }else{
            cout << endl;
        }
    }

private:
    char * _pstr;
};

void test0(){
    int a = 10;
    int && ref = std::move(a);
    cout << &a << endl;
    cout << &ref << endl;
    ref = 100;
    cout << a << endl;
}

void test1()
{
    String s1("hello");
    s1 = std::move(s1);
    s1.print();
}


int main(void){
    test1();
    return 0;
}
