#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::auto_ptr;

void test0(){
    auto_ptr<int> ap(new int(20));
    cout << *ap << endl;
    cout << ap.get() << endl;
    /* &ap; */

    auto_ptr<int> ap2 = ap;
    cout << *ap2 << endl;
    cout << ap2.get() << endl;

    //ap对资源的管理权已经移交给了ap2
    cout << *ap << endl;
}

int main(void){
    test0();
    return 0;
}
