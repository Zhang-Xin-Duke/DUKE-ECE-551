#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class SafeFile
{
public:
    //构造函数中接管资源
    SafeFile(FILE * f)
    : _fp(f)
    {
        cout << "SafeFile(FILE*)" << endl;
    }

    //析构函数中释放资源
    ~SafeFile()
    {
        cout << "~SafeFile()" << endl;
        if(_fp)
        {
            fclose(_fp);
            cout << "fclose(_fp)" << endl;
        }
    }

    //还希望拥有一些访问资源的方法
    //比如对文件进行写操作
    void write(const string & msg)
    {
        fwrite(msg.c_str(),1,msg.size(),_fp);
    }

private:
    FILE * _fp;
};

void test0(){
    //不推荐
    /* FILE * ff = fopen("wd.txt","a+"); */
    /* SafeFile sf(ff); */
    /* sf.write("hello,world\n"); */
    /* fclose(ff); */

    SafeFile sf(fopen("wd.txt","a+"));
    sf.write("hello,world\n");
    /* fclose(ff); */
}

int main(void){
    test0();
    return 0;
}
