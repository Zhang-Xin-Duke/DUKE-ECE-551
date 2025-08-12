#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::lock_guard;

int gVal = 0;
mutex mtx;//创建了互斥锁对象
          
void threadFunc()
{
    for(size_t idx = 0; idx != 10000000; ++idx)
    {
        //C++11中的lock_guard类就利用了RAII的思想，利用栈对象的生命周期
        //管理资源，当栈对象销毁的时候会自动调用析构函数
        //缺点：不能手动的进行上锁解锁
        lock_guard<mutex> lg(mtx);
        ++gVal;

        //xxxxx
        //
        //yyyy
    }
}

int main(int argc, char *argv[])
{
    thread th1(threadFunc);
    thread th2(threadFunc);

    th1.join();
    th2.join();
    
    cout << "gVal = " << gVal << endl;
    return 0;
}

