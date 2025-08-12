#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

template <class Container>
void display(const Container & con)
{
    for(auto & ele : con)
    {
        cout << ele << " ";
    }
    cout << endl;
}


void test0(){
    vector<int> nums = {1,4,6,2,5};
    nums.push_back(10);
    display(nums);
    nums.pop_back();
    display(nums);

    vector<int>::reverse_iterator it = nums.rbegin();
    cout << *it << endl;

    auto it2 = nums.rend();
    --it2;
    cout << *it2 << endl;

    cout << nums[10] << endl;
    //更安全，有越界判断
    cout << nums.at(2) << endl;

    //vector不支持在头部插入元素或删除元素
    /* cout << endl; */
    /* nums.push_front(100); */
    /* display(nums); */
    /* nums.pop_front(); */
    /* display(nums); */
}

void test1(){
    deque<int> nums = {1,4,6,2,5};
    nums.push_back(10);
    display(nums);
    nums.pop_back();
    display(nums);
    /* display<deque<int>>({1,4,5}); */

    cout << endl;
    nums.push_front(100);
    display(nums);
    nums.pop_front();
    display(nums);
}

void test2(){
    list<int> nums = {1,4,6,2,5};
    nums.push_back(10);
    display(nums);
    nums.pop_back();
    display(nums);

    cout << endl;
    nums.push_front(100);
    display(nums);
    nums.pop_front();
    display(nums);
}

int main(void){
    test0();
    return 0;
}
