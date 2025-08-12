#include <iostream>
#include <thread>
#include <atomic>

using std::cout;
using std::endl;
using std::thread;
using std::atomic;

atomic<int> gVal(0);

void threadFunc()
{
    for(size_t idx = 0; idx != 10000000; ++idx)
    {
        ++gVal;
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

