#include <iostream>
#include <memory>
#include <string>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::string;

void test0(){
    /* FILE * fp = fopen("hello.txt","a+"); */
    /* unique_ptr<FILE> up(fp); */
    /* string str1("hello,world\n"); */
    /* fwrite(str1.c_str(),1,str1.size(),fp); */
    /* fclose(fp); */

    //使用默认的删除器无法正常回收文件资源
    //因为底层使用的是delete
    //而不是fclose
    unique_ptr<FILE> up(fopen("hello.txt","a+"));
    string str1("hello,world\n");
    fwrite(str1.c_str(),1,str1.size(),up.get());
    /* fclose(up.get()); */
}

/* template <class T> */
/* struct FILECloser */
/* { */
/*     void operator()(T * fp) */
/*     { */
/*         if(fp) */
/*         { */
/*             fclose(fp); */
/*             cout << "fclose(fp)" << endl; */
/*         } */
/*     } */
/* }; */

struct FILECloser
{
    void operator()(FILE * fp)
    {
        if(fp)
        {
            fclose(fp);
            cout << "fclose(fp)" << endl;
        }
    }
};

void test1()
{
    /* unique_ptr<FILE,FILECloser<FILE>> up(fopen("hello.txt","a+")); */
    unique_ptr<FILE,FILECloser> up(fopen("hello.txt","a+"));
    string str1("hello,world\n");
    fwrite(str1.c_str(),1,str1.size(),up.get());
}

void test2()
{
    FILECloser fc;
    shared_ptr<FILE> sp(fopen("sp.txt","a+"),fc);
    string str1("hello,world\n");
    fwrite(str1.c_str(),1,str1.size(),sp.get());
    /* fclose(sp.get()); */
}



int main(void){
    test2();
    return 0;
}
