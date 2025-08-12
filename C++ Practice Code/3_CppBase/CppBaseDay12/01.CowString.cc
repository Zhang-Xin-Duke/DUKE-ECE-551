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
    CowString & operator=(const CowString &);
    
    char & operator[](size_t idx);
    


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

    void release()
    {
        decreaseRefcount();
        if(use_count() == 0){
            delete [] (_pstr - kRefcountLength);
            cout << ">>>>delete heap" << endl;
        }
        _pstr = nullptr;
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
    release();
}

CowString::CowString(const CowString & rhs)
: _pstr(rhs._pstr) // 浅拷贝
{
    increaseRefcount();
    cout << "CowString拷贝构造" << endl;
}

CowString & CowString::operator=(const CowString & rhs)
{
    if(this != &rhs)
    {
        release(); //判断+回收原本的空间       
        _pstr = rhs._pstr; //浅拷贝
        increaseRefcount();
    }
    return *this;
}

/* char & CowString::operator[](size_t idx) */
/* { */
/*     if(idx < size()) */
/*     { */
/*         return _pstr[idx]; */
/*     }else{ */
/*         cout << "out of range" << endl; */
/*         static char nullchar = '\0'; */
/*         return nullchar; */
/*     } */
/* } */

char & CowString::operator[](size_t idx)
{
    if(idx < size()) 
    {
        if(use_count() > 1)
        {
            //原本空间的引用计数-1
            decreaseRefcount();
            //进行深拷贝
            char * ptemp = malloc(_pstr);
            strcpy(ptemp,_pstr);
            //改变指向，让对象的_pstr指向新空间
            _pstr = ptemp;
            //初始化新空间的引用计数
            initRefcount();
        }
        return _pstr[idx];
    }else{
        cout << "out of range" << endl;
        static char nullchar = '\0';
        return nullchar;
    }
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

    cout << endl;
    str1 = str3;
    str2 = str4;
    cout << "str1:" << str1 << endl;
    cout << "str2:" << str2 << endl;
    cout << "str3:" << str3 << endl;
    cout << "str4:" << str4 << endl;
    cout << "str1.use_count:" << str1.use_count() << endl;
    cout << "str2.use_count:" << str2.use_count() << endl;
    cout << "str3.use_count:" << str3.use_count() << endl;
    cout << "str4.use_count:" << str4.use_count() << endl;
}

void test1()
{
    CowString s1("hello");
    CowString s2 = s1;
    /* cout << s1[0] << endl; */
    /* s1[0] = 'H'; */
    cout << s1 << endl;
    cout << s2 << endl;
}

int main(void){
    test1();
    return 0;
}
