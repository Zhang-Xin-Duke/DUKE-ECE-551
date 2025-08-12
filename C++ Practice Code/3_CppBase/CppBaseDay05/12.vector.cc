#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

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

}

int main(void){
    test0();
    return 0;
}
