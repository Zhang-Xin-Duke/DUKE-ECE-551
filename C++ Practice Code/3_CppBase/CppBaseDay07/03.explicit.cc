#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
    //将这个关键字写在特定的构造函数之前
    //那么就可以让编译器不再能够通过这个构造函数
    //完成隐式转换
    /* explicit */
    Point(int x,int y = 10)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }
    
    Point(const Point & rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << "拷贝构造" << endl;
    }


    void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
private:
   
    int _ix;
    int _iy;
};

void test0(){
    //隐式转换
    //编译器会自动地利用一个int型数据
    //创建出一个临时的Point对象
    //再通过拷贝初始化pt
    //Point pt = Point(1);
    Point pt = 1;
    pt.print();
}

int main(void){
    test0();
    return 0;
}

