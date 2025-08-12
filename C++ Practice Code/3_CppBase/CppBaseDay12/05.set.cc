#include <iostream>
#include <utility>
#include <set>
#include <string>
using std::cout;
using std::endl;
using std::set;
using std::pair;
using std::string;


//set的构造
void test0(){
    set<int> nums;
    //1.元素去重
    //2.元素进行了默认的升序排列
    set<int> nums2{1,2,4,6,3,5,6,1};
    set<int> nums3 = nums2;

    auto it = nums3.begin();
    set<int>::iterator it2 = nums3.end();
    set<int> nums4(it,--it2);

    for(auto & ele : nums4)
    {
        cout << ele << " ";
    }
    cout << endl;
}

//set的查找操作
void test1(){
    set<int> nums{1,2,4,6,8};
    int a = 1;
    size_t cnt = nums.count(a);
    cout << cnt << endl;
    cnt = nums.count(3);
    cout << cnt << endl;

    cout << endl;
    auto it = nums.find(4);
    if(it == nums.end())
    {
        cout << "set中不存在该元素" << endl;
    }else{
        cout << "set中存在这个元素" << endl;
        cout << *it << endl;
    }
}

//set的插入操作
void test2(){
    set<int> nums{1,2,4,6,8};
    pair<set<int>::iterator,bool> ret = nums.insert(20);
    if(ret.second){
        cout << "插入成功" << endl;
        cout << *ret.first << endl;
    }else{
        cout << "插入失败，该元素已经存在" << endl;
        cout << *ret.first << endl;
    }
}

void test3()
{
    pair<int,double> pa(1,2.5);
    pair<int,string> pa2 = {1,"hello"};
    pair<int,int> pa3 = {1,4};

    cout << pa.first << " " << pa.second << endl;
    cout << pa2.first << " " << pa2.second << endl;
    cout << pa3.first << " " << pa3.second << endl;
}

void test4()
{
    set<int> nums{1,2,4,6,8};
    
    //set不支持取下标
    /* nums[0]; */

    for(auto & ele : nums)
    {
        cout << ele << " ";
    }
    cout << endl;

    auto it = nums.begin();
    for(; it != nums.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    auto it2 = nums.begin();
    /* *it2 = 200; */
}

int main(void){
    test4();
    return 0;
}
