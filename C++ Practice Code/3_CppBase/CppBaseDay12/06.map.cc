#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::set;
using std::map;
using std::pair;
using std::string;
using std::make_pair;

void test0(){
    pair<int,string> pa(6,"beijing");

    map<int,string> nums = {{1,"wangdao"},
        {2,"hello"},
        {4,"world"},
        pair<int,string>(7,"hubei"),
        pair<int,string>(5,"wuhan"),
        pa,
        make_pair(6,"shanghai"),
        make_pair(3,"shenzhen"),
        make_pair(9,"shenzhen")
    };

    for(auto & pa : nums)
    {
        cout << pa.first << " " << pa.second << endl;
    }

    cout << endl;
    map<int,string>::iterator it = nums.begin();
    for(; it != nums.end(); ++it)
    {
        /* cout << (*it).first << " " << (*it).second << endl; */
        cout << it->first << " " << it->second << endl;
    }


}

void test1()
{
     map<int,string> nums = {{1,"wangdao"},
        {2,"hello"},
        {4,"world"},
        pair<int,string>(5,"wuhan"),
        make_pair(6,"shanghai"),
        };

     size_t cnt = nums.count(1);
     cout << cnt << endl;
     cnt = nums.count(10);
     cout << cnt << endl;


     auto it = nums.find(5);
     if(it == nums.end())
     {
        cout << "包含这个key的pair不存在" << endl;
     }else{
        cout << "找到了" << endl;
        cout << it->first << " " << it->second << endl;
     }
}

void test2()
{
     map<int,string> nums = {{1,"wangdao"},
        {2,"hello"},
        {4,"world"},
        pair<int,string>(5,"wuhan"),
        make_pair(6,"shanghai"),
        };

     pair<map<int,string>::iterator,bool> ret = 
         nums.insert(make_pair(4,"hello"));

     if(ret.second){
         cout << "插入成功" << endl;
         cout << ret.first->first << " " 
             << ret.first->second << endl;
     }else{
         cout << "插入失败，已经存在包含相同key的pair" << endl;
         cout << ret.first->first << " " 
             << ret.first->second << endl;
     }
}

void test3()
{
     map<int,string> nums = {{0,"wangdao"},
        {1,"guangzhou"},
        {2,"hello"},
        {4,"world"},
        pair<int,string>(5,"wuhan"),
        make_pair(6,"shanghai"),
        };

     cout << nums[0] << endl;
     cout << nums[1] << endl;
     cout << nums[2] << endl;
     cout << nums[3] << endl;


    cout << "##############" << endl;
    for(auto & pa : nums)
    {
        cout << pa.first << " " << pa.second << endl;
    }

    nums[3] = "hangzhou";
    cout << "##############" << endl;
    for(auto & pa : nums)
    {
        cout << pa.first << " " << pa.second << endl;
    }

}

int main(void){
    test3();
    return 0;
}
