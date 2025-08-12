#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

void test0(){
    vector<int> nums;
    //4个7
    vector<int> nums2(4,7);

    //传入两个迭代器，获取[)范围的元素
    vector<int> nums3(nums2.begin(),nums2.end());

    int arr[5] = {1,2,3,4,5};
    vector<int> nums4(arr,arr + 5);

    vector<int> nums5 = {2,4,5,7,3,9};

    //通过下标遍历
    for(size_t idx = 0; idx < nums2.size(); ++idx)
    {
        cout << nums2[idx] << " ";
    }
    cout << endl;

    //增强for循环
    for(auto & ele : nums3)
    {
        cout << ele << " ";
    }
    cout << endl;

    //迭代器方式遍历
    auto it = nums4.begin();
    for(; it != nums4.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //在for循环之外没有初始化迭代器
    //注意此处不能用auto
    vector<int>::iterator it2;
    for(it2 = nums5.begin(); it2 != nums5.end(); ++it2)
    {
        cout << *it2 << " ";
    }
    cout << endl;
}

void test1(){
    deque<int> nums;
    //4个7
    deque<int> nums2(4,7);

    //传入两个迭代器，获取[)范围的元素
    deque<int> nums3(nums2.begin(),nums2.end());

    int arr[5] = {1,2,3,4,5};
    deque<int> nums4(arr,arr + 5);

    deque<int> nums5 = {2,4,5,7,3,9};

    //通过下标遍历
    for(size_t idx = 0; idx < nums2.size(); ++idx)
    {
        cout << nums2[idx] << " ";
    }
    cout << endl;

    //增强for循环
    for(auto & ele : nums3)
    {
        cout << ele << " ";
    }
    cout << endl;

    //迭代器方式遍历
    auto it = nums4.begin();
    for(; it != nums4.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //在for循环之外没有初始化迭代器
    //注意此处不能用auto
    deque<int>::iterator it2;
    for(it2 = nums5.begin(); it2 != nums5.end(); ++it2)
    {
        cout << *it2 << " ";
    }
    cout << endl;
}


void test2(){
    list<int> nums;
    //4个7
    list<int> nums2(4,7);

    //传入两个迭代器，获取[)范围的元素
    list<int> nums3(nums2.begin(),nums2.end());

    int arr[5] = {1,2,3,4,5};
    list<int> nums4(arr,arr + 5);

    list<int> nums5 = {2,4,5,7,3,9};

    //list不支持下标访问
    /* for(size_t idx = 0; idx < nums2.size(); ++idx) */
    /* { */
    /*     cout << nums2[idx] << " "; */
    /* } */
    /* cout << endl; */

    //增强for循环
    for(auto & ele : nums3)
    {
        cout << ele << " ";
    }
    cout << endl;

    //迭代器方式遍历
    auto it = nums4.begin();
    for(; it != nums4.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //在for循环之外没有初始化迭代器
    //注意此处不能用auto
    list<int>::iterator it2;
    for(it2 = nums5.begin(); it2 != nums5.end(); ++it2)
    {
        cout << *it2 << " ";
    }
    cout << endl;
}

int main(void){
    test1();
    return 0;
}
