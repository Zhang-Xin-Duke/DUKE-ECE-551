#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
using namespace log4cpp;

int main(int argc, char** argv) {
    //输出器的部分
    //基类指针指向派生类对象
	/* Appender *appender1 = */ 
        /* new OstreamAppender("console", &std::cout); */

    //OstreamAppender构造函数的第一个参数表示目的地名称
    //随便写，仅仅给程序员一个提示而已
    //第二个参数才是真正决定了日志的目的地
	OstreamAppender *appender1 = 
        new OstreamAppender("console", &std::cout);
    //目的地与布局绑定
	appender1->setLayout(new BasicLayout());


    //准备的第二个输出器
    //FileAppender构造函数的第一个参数表示目的地名称
    //随便写，仅仅给程序员一个提示而已
    //第二个参数表示将日志保存到的文件名
	FileAppender *appender2 = 
        new FileAppender("default", "program.log");
	appender2->setLayout(new BasicLayout());


    //创建了root节点的记录器
	Category& root = Category::getRoot();
    //通过记录器设置系统优先级
	root.setPriority(Priority::WARN);
    //记录器绑定目的地
	root.addAppender(appender1);

    //创建了root节点之下的Category叶子结点（也是记录器）
    //引用名sub1仅仅只是代码中使用的名字
    //用来绑定叶子节点Category对象
    //getInstance的参数sub1才是叶子结点真正的名字
	Category& sub1 = Category::getInstance("sub1");
	/* Category& sub11 = Category::getInstance("sub1.sub11"); */

    //也可以重新设置门槛（系统优先级）
	/* sub1.setPriority(Priority::ERROR); */
    //增加了一个目的地
	sub1.addAppender(appender2);
    //也可以不继承父节点的目的地
    /* sub1.setAdditivity(false); */


	// use of functions for logging messages
	root.error("root error");//输出到终端
	root.info("root info");//过滤
	sub1.error("sub1 error");//终端和文件
	sub1.warn("sub1 warn");//终端和文件

	// printf-style for logging variables
	root.warn("%d + %d == %s ?", 1, 1, "two");//输出到终端

	// use of streams for logging messages
	root << Priority::ERROR << "Streamed root error";//终端
	root << Priority::INFO << "Streamed root info";//过滤
	sub1 << Priority::ERROR << "Streamed sub1 error";//终端和文件
	sub1 << Priority::WARN << "Streamed sub1 warn";//终端和文件

	// or this way:
	root.errorStream() << "Another streamed error";//终端

	return 0;
}
