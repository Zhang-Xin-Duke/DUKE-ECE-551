#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class CowString
{
public:
    CowString();
    CowString(const char *);
    ~CowString();
    CowString(const CowString &);
    /* CowString & operator=(const CowString &); */

    const char * c_str() const
    {
        return _pstr;
    }

    size_t size() const
    {
        return strlen(_pstr);
    }

    int use_count()
    {
        return *(int*)(_pstr - kRefcountLength);
    }

    friend
    ostream & operator<<(ostream & os,const CowString & rhs);
private:
    char * malloc(const char * pstr = nullptr)
    {
        if(pstr){
            return new char[strlen(pstr) + 1 + kRefcountLength]() + kRefcountLength;
        }else{
            return new char[1 + kRefcountLength]() + kRefcountLength;
        }
    }


    void initRefcount()
    {
        *(int*)(_pstr - kRefcountLength) = 1;
    }

    void increaseRefcount()
    {
        ++*(int*)(_pstr - kRefcountLength);
    }

    void decreaseRefcount()
    {
        --*(int*)(_pstr - kRefcountLength);
    }
private:
    static const int kRefcountLength = 4;
    char * _pstr;
};

//cout << str1 << endl;
ostream & operator<<(ostream & os,const CowString & rhs)
{
    if(rhs._pstr)
    {
        os << rhs._pstr;
    }
    return os;
}

CowString::CowString()
: _pstr(malloc())
{
    cout << "CowString()" << endl;
    initRefcount();
}

CowString::CowString(const char * pstr)
: _pstr(malloc(pstr))
{
    cout << "CowString(const char *)" << endl;
    strcpy(_pstr,pstr);
    initRefcount();
}

CowString::~CowString()
{
    cout << "~CowString()" << endl;
    decreaseRefcount();
    if(use_count() == 0){
        delete [] (_pstr - kRefcountLength);
        cout << ">>>>delete heap" << endl;
    }
    _pstr = nullptr;
}

CowString::CowString(const CowString & rhs)
: _pstr(rhs._pstr) // 浅拷贝
{
    increaseRefcount();
    cout << "CowString拷贝构造" << endl;
}


void test0(){
    CowString str1;
    CowString str2 = str1;
    cout << "str1:" << str1 << endl;
    cout << "str2:" << str2 << endl;
    cout << "str1.use_count:" << str1.use_count() << endl;
    cout << "str2.use_count:" << str2.use_count() << endl;

    cout << endl;
    CowString str3("hello");
    CowString str4 = str3;
    cout << "str3:" << str3 << endl;
    cout << "str4:" << str4 << endl;
    cout << "str3.use_count:" << str3.use_count() << endl;
    cout << "str4.use_count:" << str4.use_count() << endl;

}

int main(void){
    test0();
    return 0;
}
