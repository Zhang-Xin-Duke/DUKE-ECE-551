#include <string.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T>
T add(T t1, T t2)
{
    return t1 + t2;
}
//使用普通函数实现
const char* add(const char* p1, const char* p2)
{
    char* ptemp = new char[strlen(p1) + strlen(p2) + 1]();
    strcpy(ptemp, p1);
    strcat(ptemp, p2);
    return ptemp;
}

//特化模板
//针对通用模板解决不了的一些类型
//单独准备一套处理逻辑
//特化模板不能脱离于通用模板存在
//并且需要和通用模板形式一致
template <>
const char * add<const char *>(const char * p1,const char * p2)
{
    char * ptemp = new char[strlen(p1) + strlen(p2) + 1]();
    strcpy(ptemp,p1);
    strcat(ptemp,p2);
    return ptemp;
}

void test0(){
    cout << add(1,2) << endl;

    const char * pstr1 = "hello,";
    const char * pstr2 = "world!";
    //const char * + const char * 不能直接相加
    /* cout << add<string>(pstr1,pstr2) << endl; */ 
    /* cout << add(pstr1,pstr2) << endl; */
    const char * res = add(pstr1,pstr2);
    cout << res << endl;
    delete [] res;
}

int main(void){
    test0();
    return 0;
}
