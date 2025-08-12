#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void test0(){
    vector<int> nums = {2,4,8,3,6};
    cout << &nums << endl;//对象首地址
    cout << &nums[0] << endl;
    cout << &nums.front() << endl;
    cout << &*nums.begin() << endl;
    cout << nums.data() << endl;
}

int main(void){
    test0();
    return 0;
}
