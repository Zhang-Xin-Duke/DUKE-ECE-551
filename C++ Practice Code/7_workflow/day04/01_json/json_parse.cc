#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
using namespace std;
int main(){
    ifstream ifs("info.json");
    char *buf = new char[122]{0};
    ifs.read(buf,121); //读取文件内容
    nlohmann::json json = nlohmann::json::parse(buf);//反序列化
    json["key3"]["key5"] = 5678;//修改
    
    cout << json.dump() << "\n";
    delete []buf;
    return 0;
}

