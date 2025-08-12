#include <iostream>
#include <fstream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
using std::cout;
using std::endl;
using namespace log4cpp;

void test1(){
    //1.准备好布局
    PatternLayout * ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout * ptn3 = new PatternLayout();
    ptn3->setConversionPattern("%d %c [%p] %m%n");

    //2.创建目的地对象
    OstreamAppender * pos = 
        new OstreamAppender("console",&cout);
    pos->setLayout(ptn1);

    //布局与目的地需要一一对应
    FileAppender * pfile = 
        new FileAppender("file","res.txt");
    pfile->setLayout(ptn2);

    RollingFileAppender * pRoll =
        new RollingFileAppender("roll","rolling.txt",
                                5 * 1024,
                                9);
    pRoll->setLayout(ptn3);


    //3.创建记录器对象
    Category & sub1 = Category::getRoot().getInstance("sub1");

    //4.设置优先级和目的地
    sub1.setPriority(Priority::DEBUG);
    sub1.addAppender(pos);
    sub1.addAppender(pfile);
    sub1.addAppender(pRoll);

    //5.利用记录器写日志
    int count = 30;
    while(count-- > 0)
    {
        sub1.emerg("this is an emerg msg");
        sub1.fatal("this is a fatal msg");
        sub1.alert("this is an alert msg");
        sub1.crit("this is a crit msg");
        sub1.error("this is an error msg");
        sub1.warn("this is a warn msg");
        sub1.notice("this is a notice msg");
        sub1.info("this is an info msg");
        sub1.debug("this is a debug msg");
    }


    Category::shutdown();
}

int main(void){
    test1();
    return 0;
}
