#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CharArray
{
public:
    CharArray(const char * pstr)
    : _capacity(strlen(pstr) + 1)
    , _data(new char[_capacity]())
    {
        strcpy(_data,pstr);
    }

    ~CharArray()
    {
        if(_data)
        {
            delete [] _data;
            _data = nullptr;
        }
    }
    
    char & operator[](size_t idx) 
    {
        if(idx < _capacity - 1)
        {
            return _data[idx];
        }else{
            cout << "out of range!!!" << endl;
            static char nullchar = '\0';
            return nullchar;

            /* return '\0';//error */
        }
    }

    //前一个const的作用是返回值是一个const引用
    //不能对返回值进行修改操作
    //后一个const的作用是提供给const对象使用
    //在函数体中不能修改对象的数据成员
    const char & operator[](size_t idx) const
    {
        if(idx < _capacity - 1)
        {
            //只能人为避免
            /* _data[idx] = 'X'; */
            return _data[idx];
        }else{
            cout << "out of range!!!" << endl;
            static char nullchar = '\0';
            return nullchar;
        }
    }

    //不测试复制赋值
private:
    size_t _capacity;
    char * _data;
};

void test0(){
    char arr[] = "hello";
    cout << arr[0] << endl;
    arr[0] = 'H';
    cout << arr[0] << endl;

    CharArray ca("world");
    cout << ca[0] << endl;
    ca[0] = 'W';
    cout << ca[0] << endl;

    const CharArray ca2("wangdao");
    cout << ca2[0] << endl;
    /* ca2[0] = 'W'; */
    cout << ca2[0] << endl;



}

int main(void){
    test0();
    return 0;
}
