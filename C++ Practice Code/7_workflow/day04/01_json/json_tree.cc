#include "nlohmann/json.hpp"
#include <iostream>
#include <string>
using namespace std;
int main(){
    nlohmann::json json; //nlohmann::json就是树形结构的类型
    //json的第一次新增操作，决定了它是object还是array
    json["key1"] = 1234; //object
    json["key2"]["key3"] = 1234; // json "key2" --> {"key3":1234}
    json["key2"]["key4"] = "1234"; // "key2" --> {"key3":1234,"key4":"1234"}
    json["key5"][0] = "1234"; // "key5" --> ["1234"]
    string output = json.dump(); //dump 序列化
    cout << output << "\n";
    return 0;
}
