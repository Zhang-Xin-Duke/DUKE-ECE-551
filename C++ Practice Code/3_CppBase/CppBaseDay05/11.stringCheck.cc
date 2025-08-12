#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test0(){
    string str1("wangdao");

    /* cout << str1[0] << endl; */
    /* cout << str1[1] << endl; */

    //1.利用下标进行遍历
    for(size_t idx = 0; idx < str1.size(); ++idx)
    {
        cout << str1[idx] << " ";
    }
    cout << endl;

    //2.增强for循环(c++11)
    //通常与auto连用，效果是
    //从容器中自动地按顺序取出元素
    //加引用，ch代表了str1的元素本身
    //不加引用，就是元素的副本
    /* for(auto & ch : str1) */
    /* { */
    /*     ++ch; */
    /* } */
    /* cout << str1 << endl; */

    for(auto & ch : str1)
    {
        cout << ch << " ";
    }
    cout << endl;

    //3.利用迭代器进行遍历
    auto it = str1.begin();
    for(; it != str1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(void){
    test0();
    return 0;
}
