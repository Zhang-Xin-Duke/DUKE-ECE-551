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
    list<int> nums = {2,5,8,3,3,4,9};
    auto it = nums.begin();
    ++it;
    ++it;
    nums.insert(it,80);
    display(nums);

    nums.insert(it,3,100);
    display(nums);

    /* cout << *it << endl; */

    int arr[5] = {12,13,14,15,16};
    nums.insert(it,arr,arr + 5);
    display(nums);

    nums.insert(it,{300,301,302});
    display(nums);
}

void test1(){
    deque<int> nums = {2,5,8,3,3,4,9};
    auto it = nums.begin();
    ++it;
    ++it;
    cout << *it << endl;

    it = nums.insert(it,80);
    display(nums);
    cout << *it << endl;

    it = nums.insert(it,3,100);
    display(nums);
    cout << *it << endl;

    int arr[5] = {12,13,14,15,16};
    it = nums.insert(it,arr,arr + 5);
    display(nums);
    cout << *it << endl;

    it = nums.insert(it,{300,301,302});
    display(nums);
    cout << *it << endl;
}

void test2(){
    vector<int> nums = {2,5,8,3,3,4,9};
    auto it = nums.begin();
    ++it;
    ++it;
    //更新迭代器
    it = nums.insert(it,80);
    display(nums);

    cout << *it << endl;

    it = nums.insert(it,3,100);
    display(nums);
    cout << *it << endl;
    
    --it;
    cout << *it << endl;

    int arr[5] = {12,13,14,15,16};
    it = nums.insert(it,arr,arr + 5);
    display(nums);

    it = nums.insert(it,{300,301,302});
    display(nums);
}

void test3()
{
    deque<int> nums = {1,2,3,4,5};
    auto it = nums.begin();
    ++it;
    ++it;
    nums.insert(it,100);
    display(nums);
    cout << *it << endl;
}


int main(void){
    test1();
    return 0;
}
