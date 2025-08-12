#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

//vector的创建方式
void test0(){
    int arr[5] = {1,2,3,4,5};

    vector<int> nums;

    //5代表元素个数，每个元素被初始化为该类型默认值
    vector<long> nums2(5);
    for(auto & l : nums2)
    {
        cout << l << " ";
    }
    cout << endl;

    //3个7
    vector<int> nums3(3,7);
    for(auto & l : nums3)
    {
        cout << l << " ";
    }
    cout << endl;

    vector<int> nums4{1,2,3,4,5};
    for(auto & l : nums4)
    {
        cout << l << " ";
    }
    cout << endl;

    //传入两个迭代器first/last初始化vector
    //使用[first,last)范围内的元素来初始化
    vector<int> nums5(nums4.begin(),nums4.end() - 2);
    for(auto & l : nums5)
    {
        cout << l << " ";
    }
    cout << endl;

    vector<int> nums6(arr,arr + 5);
    for(auto & l : nums6)
    {
        cout << l << " ";
    }
    cout << endl;
}

//vector的基本操作
void test1(){
    vector<int> nums{1,2,3,4,5};

    vector<int>::iterator it = nums.begin();
    auto it2 = nums.end();

    cout << *it << endl;
    --it2;
    cout << *it2 << endl;//注意安全性

    cout << endl;
    vector<int> nums2;
    cout << nums.empty() << endl;
    cout << nums2.empty() << endl;

    cout << endl;
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;

    cout << "nums2'size:" << nums2.size() << endl;
    cout << "nums2'capacity:" << nums2.capacity() << endl;
}

//动态扩容
void test2(){
    vector<int> nums{2,4,6,8,10};
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;

    cout << endl;
    /* int a = 10; */
    /* nums.push_back(a); */
    nums.push_back(10);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;

    for(auto & l : nums)
    {
        cout << l << " ";
    }
    cout << endl;

    //删除最后一个元素
    nums.pop_back();
    for(auto & l : nums)
    {
        cout << l << " ";
    }
    cout << endl;
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    
    nums.clear();
    cout << endl;
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
}

void test3()
{
    vector<int> nums{2,4,6,8,10};
    nums.push_back(12);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;

    cout << endl;
    nums.shrink_to_fit();
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;

    cout << endl;
    vector<int> nums2{1,2,3};
    nums2.push_back(4);
    cout << "nums2'size:" << nums2.size() << endl;
    cout << "nums2'capacity:" << nums2.capacity() << endl;

    vector<int> nums3 = nums2;
    cout << "nums3'size:" << nums3.size() << endl;
    cout << "nums3'capacity:" << nums3.capacity() << endl;
}

void test4()
{
    //预期vector存放100个元素
    
    //会涉及多次动态扩容，效率低
    /* vector<int> nums; */
    /* nums.push_back(1); */
    /* nums.push_back(2); */
    /* nums.push_back(3); */

    //100个元素会完成初始化
    //首先会有初始化的开销
    //其次后续想要灵活地保存元素，还需要去修改元素
    /* vector<int> nums(100); */
    /* nums[0] = 1; */

    vector<int> nums;
    nums.reserve(100);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
}

//vector的遍历(重要！！！)
void test5()
{
    vector<int> nums{1,2,5,7,9};
    /* cout << nums[0] << endl; */
    /* cout << nums[1] << endl; */
    //1.
    for(size_t idx = 0; idx < nums.size(); ++idx)
    {
        cout << nums[idx] << " ";
    }
    cout << endl;

    //2.
    for(auto & nu : nums)
    {
        cout << nu << " ";
    }
    cout << endl;

    //3.
    auto it = nums.begin();
    for(; it != nums.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(void){
    test5();
    return 0;
}
