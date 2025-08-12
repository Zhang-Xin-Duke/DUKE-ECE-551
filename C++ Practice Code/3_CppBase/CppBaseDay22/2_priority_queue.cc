#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

void test0()
{
    vector<int> vec = {1, 5, 7, 6, 9, 4, 7};
    priority_queue<int> pque(vec.begin(), vec.end());

    while(!pque.empty())
    {
        cout << "优先级最高的元素 " << pque.top() << endl;
        pque.pop();
    }
}

void test()
{
    vector<int> vec = {1, 5, 7, 6, 9, 4, 7};
    //优先级队列的底层实现使用的是堆排序：默认是大根（顶）堆
    //步骤：当有元素插入的时候，会将堆顶与新插入的元素进行比较，如果堆顶
    //比新插入的元素要小，那么就满足std::less,就会将新插入的元素作为新的
    //堆顶；如果新插入的元素与堆顶进行比较，发现堆顶比新插入的元素要大，
    //就不满足std::less,那么老的堆顶依旧是堆顶
    priority_queue<int> pque;

    for(size_t idx = 0; idx != vec.size(); ++idx)
    {
        pque.push(vec[idx]);
        cout << "优先级最高的元素 " << pque.top() << endl;
    }

    while(!pque.empty())
    {
        cout <<  pque.top() << "  ";
        pque.pop();
    }
    cout <<endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

