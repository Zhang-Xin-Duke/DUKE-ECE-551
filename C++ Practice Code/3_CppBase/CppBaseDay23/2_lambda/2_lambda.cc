#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int gNum = 135;

void test()
{
    int num = 10;
    string name("wangdao");
    int age = 100;

    //对于每个局部变量而言，可以分别才有值捕获或者引用捕获
    [num, &age](int value){
        ++value;
        cout << "value = " << value << endl;
        cout << "num = " << num << endl;
        ++age;
        cout << "age = " << age << endl;
        cout << "gNum = " << gNum << endl;
    }(111);

    cout << endl << endl;
    /* [num, name, age](int value){//ok */
    //如果想将外部所有的局部变量做值捕获，可以简化为=
    [=](int value){
        ++value;
        cout << "value = " << value << endl;
        cout << "num = " << num << endl;
        cout << "name = " << name << endl;
        cout << "age = " << age << endl;
    }(222);

    cout << endl << endl;
    /* [&num, &name, &age](int value){//ok */
    //如果想将外部所有的局部变量做引用捕获，可以简化为&
    [&](int value){
        ++value;
        cout << "value = " << value << endl;
        ++num;
        cout << "num = " << num << endl;
        name = "wuhan";
        cout << "name = " << name << endl;
        ++age;
        cout << "age = " << age << endl;
    }(333);

    cout << endl << endl;
    /* [num, &age, &name](int value){ */
    [&, num](int value){
        ++value;
        cout << "value = " << value << endl;
        cout << "num = " << num << endl;
        name = "wuhan";
        cout << "name = " << name << endl;
        ++age;
        cout << "age = " << age << endl;
    }(444);

    cout << endl << endl;
    /* [&num, age, name](int value){ */
    [=, &num](int value){
        ++value;
        cout << "value = " << value << endl;
        ++num;
        cout << "num = " << num << endl;
        cout << "name = " << name << endl;
        cout << "age = " << age << endl;
    }(555);
}

void test2()
{
    auto f = [](int value){

    };

    f(10);
    f(20);
    f(30);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

