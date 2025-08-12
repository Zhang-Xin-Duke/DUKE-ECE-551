#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void test0(){
    vector<int> nums;
    cout << sizeof(nums) << endl;
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    cout << endl;

    nums.push_back(1);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    cout << endl;
    nums.push_back(1);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    cout << endl;
    nums.push_back(1);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    cout << endl;
    nums.push_back(1);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    cout << endl;
    nums.push_back(1);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    cout << endl;
    nums.push_back(1);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    cout << endl;
    nums.push_back(1);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    cout << endl;
    nums.push_back(1);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    cout << endl;
    nums.push_back(1);
    cout << "nums'size:" << nums.size() << endl;
    cout << "nums'capacity:" << nums.capacity() << endl;
    cout << endl;

    cout << sizeof(nums) << endl;


}

int main(void){
    test0();
    return 0;
}
