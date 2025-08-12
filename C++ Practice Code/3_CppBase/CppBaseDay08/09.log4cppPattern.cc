#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
using std::cout;
using std::endl;
using namespace log4cpp;

void test0(){
    //1.准备好布局
    PatternLayout * ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    //2.创建目的地对象
    OstreamAppender * pos = 
        new OstreamAppender("console",&cout);
    pos->setLayout(ptn1);


    //3.创建记录器对象
    Category & sub1 = Category::getRoot().getInstance("sub1");

    //4.设置优先级和目的地
    sub1.setPriority(Priority::DEBUG);
    sub1.addAppender(pos);

    //5.利用记录器写日志
    sub1.error("this is an error msg");
    sub1.warn("this is a warn msg");
    sub1.notice("this is a notice msg");




}

int main(void){
    test0();
    return 0;
}
