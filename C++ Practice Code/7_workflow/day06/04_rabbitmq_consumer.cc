#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <string>
#include <iostream>
using namespace std;
using namespace AmqpClient;
struct MQInfo{
    string Exchange = "62file_exchange";
    string RoutingKey = "fileinfo";
    string Queue = "62file_queue";
};
int main(){
    MQInfo info;
    // 建立和Rabbitmq的连接
    Channel::ptr_t channel = Channel::Create(); 
    // 开启非阻塞消费模式
    channel->BasicConsume(info.Queue);
    // 准备一个信封
    Envelope::ptr_t envelope;
    // 消费一条消息
    bool flag = channel->BasicConsumeMessage(envelope,3000);
    if(flag){
        cout << "Success , content = " << envelope->Message()->Body() << "\n"; 
    }
    else{
        cout << "Fail, time out!\n";
    }
    return 0;
}
