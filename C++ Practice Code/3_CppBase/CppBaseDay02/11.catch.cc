#include <iostream>
using std::cout;
using std::endl;

double division(double x,double y)
{
    if(y == 0){
        /* cout << "除数为0，没有意义" << endl; */
        throw "除数为0，没有意义";
    }else if(x == 0){
        throw 0;
    }else{
        return x / y;
    }
}

void test0(){
    try{
        double a = 100;
        double b = 0;
        /* cout << division(a,b) << endl; */
        cout << division(b,a) << endl;
    }catch(const char *){//catch的是异常类型
        /* cout << msg << endl;//进行具体的异常处理 */
        cout << "除0啦，傻瓜" << endl;
    }catch(int){
        cout << "结果为0" << endl;
    }
    cout << "over" << endl;
}

int main(void){
    test0();
    return 0;
}
