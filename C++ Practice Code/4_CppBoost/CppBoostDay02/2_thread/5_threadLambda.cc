#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;


int main(int argc, char *argv[])
{
    cout << "main thread id = " << std::this_thread::get_id() << endl;

    thread th([](int x){
              cout << "void lambda(int)" << endl;
              cout << "x = " << x << endl;
              cout << "child thread id = " 
                   << std::this_thread::get_id() << endl;
              }, 5);

    cout << "th child thread = " << th.get_id() << endl;
    th.join();//让主线程等待子线程

    return 0;
}

