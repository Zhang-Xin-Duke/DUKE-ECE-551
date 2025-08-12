// gcc echoall.c -o echoall -Wall -g
#include <func.h>

int main(int argc, char* argv[])
{
    // 打印进程的pid
    printf("pid = %d, ppid = %d\n", getpid(), getppid());

    // 打印命令行参数
    printf("CommandLine Arguments: \n");
    for(int i = 0; i < argc; i++) {
        printf("    %s\n", argv[i]);
    }

    // 打印环境变量
    printf("Environment Variables: \n");
    extern char** environ; // 引用其它文件中定义的environ变量
    char** p = environ;
    while (*p != NULL) {
        printf("    %s\n", *p);
        p++;
    }
    return 0;
}
