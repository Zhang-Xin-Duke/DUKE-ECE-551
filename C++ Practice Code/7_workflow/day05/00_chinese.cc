#include <iostream>
#include <string>
using namespace std;
int main(){
    string str = "hello世界nihao";
    for(size_t i = 0; i < str.size();){
        // 1000 0000 & ch
        if((str[i] & 0x80) == 0){
            cout << "english ch = " << str.substr(i,1) << "\n";
            ++i;
        } 
        else{
            cout << "chinese ch = " << str.substr(i,3) << "\n";
            i += 3;
        }
    }
    return 0;
}

