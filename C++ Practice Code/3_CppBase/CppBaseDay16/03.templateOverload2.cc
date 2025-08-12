#include <iostream>
using std::cout;
using std::endl;

//不推荐在一个源文件中定义多个通用模板构成重载
//模板二的适用性更广，就不需要模板一了
#if 0
template <typename T>
T add(T t1, T t2)
{
    cout << "模板一" << endl;
    return t1 + t2;
}
#endif

template <class T1,class T2>
T1 add(T1 t1, T2 t2)
{
    cout << "模板二" << endl;
    return t1 + t2;
}


void test1(){
    //重载时分析比较麻烦
    
    int x = 10;
    double y = 3.7;
    //模板二
    cout << add(x,y) << endl;
    //模板二
    cout << add<double,int>(y,x) << endl;
    //模板一
    cout << add(x,x) << endl;

    //如果使用模板二，两个参数都不需要做出类型转换
    //T1被指定为int，而x本身就是int，y仍然依靠推导
    //将T2推导为double
    cout << add<int>(x,y) << endl;
    
    //模板一
    cout << add<int>(y,x) << endl;
}

int main(void){
    test1();
    return 0;
}
