// 找到头文件
#include <signal.h>
#include <workflow/WFFacilities.h>
#include <iostream>

using std::cout;
using std::cerr;
//定义一个全局变量
static WFFacilities::WaitGroup waitGroup(1);
void sighandler(int signum){
    waitGroup.done();
}
int main(){
    signal(SIGINT,sighandler);
    waitGroup.wait();
    cout << "finished!\n"; //不使用std::endl
}