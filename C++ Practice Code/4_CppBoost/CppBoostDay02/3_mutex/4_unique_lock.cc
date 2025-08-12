#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::unique_lock;

int gVal = 0;
mutex mtx;//创建了互斥锁对象
          
void threadFunc()
{
    for(size_t idx = 0; idx != 10000000; ++idx)
    {
        //C++11中的unique_lock类就利用了RAII的思想，利用栈对象的生命周期
        //管理资源，当栈对象销毁的时候会自动调用析构函数
        //unique_lock相对于lock_guard而言，还提供了手动上锁与解锁的操作
        //所以更加灵活一些,但是lock_guard比unique_lock的效率高一些
        unique_lock<mutex> ul(mtx);
        ++gVal;
        ul.unlock();

        //xxxxx
        ul.lock();
        //yyyy
        ul.unlock();
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

