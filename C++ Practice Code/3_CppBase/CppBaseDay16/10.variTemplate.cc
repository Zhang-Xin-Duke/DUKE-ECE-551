#include <iostream>
using std::cout;
using std::endl;

//Args代表模板参数包
//args代表函数参数包
//省略号在参数包的左边，属于打包
template <class ...Args>
void display(Args ...args)
{
    cout << sizeof...(Args) << endl;
    cout << sizeof...(args) << endl;
}

void test0(){
    display(1,3.6);
    display(2,7.8,'d',"hello",true);
    display(2,7.8,'d',"hello",true,10);
}

int main(void){
    test0();
    return 0;
}
