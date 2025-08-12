#include "nlohmann/json.hpp"
#include <iostream>
#include <string>
using namespace std;
int main(){
    nlohmann::json json; //nlohmann::json就是树形结构的类型
    //json的第一次新增操作，决定了它是object还是array
    json["key1"] = 1234; // operator[](string) --> json是一个object
    json["key2"] = "value2";

    string output = json.dump(); //dump 序列化
    cout << output << "\n";
    return 0;
}
