#include <iostream>
using std::cout;
using std::endl;

void test0(){
    int * p = (int*)malloc(sizeof(int));
    *p = 100;
    cout << *p << endl;
    free(p);

    //初始化为400
    int * p1 = new int(400);
    cout << *p1 << endl;
    delete p1;
    /* free(p1); */

    //默认初始化
    //int型的默认值为0
    int * p2 = new int();
    cout << *p2 << endl;
    delete p2;

    //不推荐
    //因为不能在所有的平台上都确保完成初始化
    /* int * p3 = new int; */
    /* cout << *p3 << endl; */
}

int main(void){
    test0();
    return 0;
}
