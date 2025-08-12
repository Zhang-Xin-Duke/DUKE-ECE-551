#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <string>
using namespace std;
using namespace AmqpClient;
struct MQInfo{
    string Exchange = "62file_exchange";
    string RoutingKey = "fileinfo";
};
int main(){

    MQInfo info;
    // 建立和Rabbitmq的连接
    Channel::ptr_t channel = Channel::Create(); 
    // 准备好一个要发送的消息
    BasicMessage::ptr_t message = BasicMessage::Create("{\"filepath\":\"1.txt\"}");
    // 发送消息
    channel->BasicPublish(info.Exchange,info.RoutingKey,message);
    return 0;
}
