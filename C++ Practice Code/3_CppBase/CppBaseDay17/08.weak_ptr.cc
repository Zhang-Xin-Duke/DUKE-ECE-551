#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

/* weak_ptr<int> wp; */

void test0(){
    weak_ptr<int> wp;
    shared_ptr<int> sp(new int(77));
    /* shared_ptr<int> sp; */
    wp = sp;

    weak_ptr<int> wp2(sp);
    shared_ptr<int> sp2 = sp;

    cout << sp.use_count() << endl;
    cout << wp.use_count() << endl;

    /* *wp; //error */
    if(sp)
    {
        cout << "资源存在" << endl;
    }

    //lock函数可以创建一个新的shared_ptr
    shared_ptr<int> sp3 = wp.lock();
    cout << sp3.use_count() << endl;
    /* *wp; */

    //等价于use_count() == 0
    //资源存在，说明有shared_ptr管理着
    //use_count()就不会等于0
    //对应的返回false
    if(wp.expired())
    {
        cout << "资源不存在" << endl;
    }else{
        cout << "资源存在" << endl;
    }



}

int main(void){
    test0();

    /* cout << endl; */
    /* cout << wp.use_count() << endl; */
    return 0;
}
