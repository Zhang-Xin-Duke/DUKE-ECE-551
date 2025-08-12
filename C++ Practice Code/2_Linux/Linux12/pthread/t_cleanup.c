#include <func.h>

void cleanup(void* arg) {
    char* msg = (char*) arg;
    puts(msg);
}

void* start_routine(void* arg) {
    // 1. 注册线程清理函数
    pthread_cleanup_push(cleanup, "111");
    pthread_cleanup_push(cleanup, "222");
	pthread_cleanup_push(cleanup, "333");

    // 不会导致线程的终止！
    pthread_cleanup_pop(1);
    // 2. 线程执行逻辑
    printf("new thread start\n");
    sleep(3);
    printf("new thread end\n");

    // 3. 线程退出
    pthread_exit(NULL);
    /* return NULL; */
    // return NULL;

    pthread_cleanup_pop(0);  // 永远执行不了
	pthread_cleanup_pop(0);
}

int main(int argc, char* argv[])
{
    pthread_t tid;
    pthread_create(&tid, NULL, start_routine, NULL);

	// sleep(1);
    // 给子线程发送取消请求
    // pthread_cancel(tid);

    // 主线程等待子线程结束
    pthread_join(tid, NULL);
    return 0;
}
