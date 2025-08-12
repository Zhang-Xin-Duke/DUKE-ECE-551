#include <iostream>
#include <mutex>
#include <thread>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;

int gVal = 0;
mutex mtx;//创建了互斥锁对象
          
class MutexLockGuard
{
public:
    MutexLockGuard(mutex &mutx)
    : _mtx(mutx)
    {
        _mtx.lock();
    }

    ~MutexLockGuard()
    {
        _mtx.unlock();
    }

private:
    mutex &_mtx;
};

void threadFunc()
{
    for(size_t idx = 0; idx != 10000000; ++idx)
    {
        //为了防止只上锁，但是忘了解锁的问题，可以将mutex进行优化改造
        //可利用RAII的思想：利用了栈对象的生命周期管理资源
        MutexLockGuard autoLock(mtx);
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

