#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    /* Point(){} */
    Point(int x = 0,int y = 0)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    void print() const
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
 
    /* ~Point() */
    /* { */
    /*     cout << "~Point()" << endl; */
    /* } */
private:
    int _ix;
    int _iy;
};


void test0(){
    Point pt(1,2);
    Point * p1 = &pt;

    Point * p2 = nullptr;
    Point * p3 = new Point(1,2);
    delete p3;
    p3 = nullptr;

    Point * p4 = new Point();
    p4->print();
    (*p4).print();
    delete p4;
    p4 = nullptr;

    //注意区分
    Point pt2;

    /* int * pint = new int(); */
}

void test1(){
    /* Point pt1(1,2); */
    /* Point pt2(3,4); */
    /* Point pt3(5,6); */
    /* Point arr[3] = {pt1,pt2,pt3}; */
    /* cout << &pt1 << endl; */
    /* cout << arr << endl; */

    /* Point arr2[3] = {Point(1,2),Point(3,4)}; */
    /* arr2[0].print(); */
    /* arr2[1].print(); */
    /* arr2[2].print(); */

    //能够匹配合适的构造函数
    //完成Point数组元素的初始化
    Point arr3[3] = {{1,2},{3,4},{5,6}};
    arr3[0].print();
    arr3[1].print();
    arr3[2].print();
}

int main(void){
    test1();
    return 0;
}
