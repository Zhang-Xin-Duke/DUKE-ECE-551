#include <iostream>
#include <functional>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::function;
using std::string;
using std::vector;

vector<function<void(const string &)>> vec;//全局变量

void test()
{
    int num = 100;
    string name("wangdao");

    vec.push_back([&num, &name](const string &value){
                  cout << "num = " << num << endl;
                  cout << "name = " << name << endl;
                  cout << "value = " << value << endl;
                  });

    /* for(auto func : vec) */
    /* { */
    /*     func("wuhan"); */
    /* } */
} 

void test2()
{
    for(auto func : vec)
    {
        func("wuhan");
    }
}


int main(int argc, char *argv[])
{
    test();
    test2();
    return 0;
}

