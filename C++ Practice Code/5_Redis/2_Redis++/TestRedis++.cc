#include <sw/redis++/redis++.h>
#include <iostream>

using namespace std;
using namespace sw::redis;

int main()
{
    auto redis = Redis("tcp://127.0.0.1:6379");

    redis.set("name", "武汉");
    auto val = redis.get("name");   
    if (val) 
    {
        std::cout << *val << std::endl;
    }
  
    
    return 0;
}
