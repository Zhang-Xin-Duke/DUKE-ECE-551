#include <func.h>

// 初始化
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* start_routine(void* arg) {
    long long* value = (long long *)arg;
    for (int i = 0; i < 10000000; i++) {
		// 上锁
		pthread_mutex_lock(&mtx);
        (*value)++;
		pthread_mutex_unlock(&mtx);
		// 释放锁
    }
    return NULL;
}

int main(void) {
    long long* value = (long long*) calloc(1, sizeof(long long));

    // 创建两个线程
    // 第一个线程执行 (*value)++ 10000000次
    // 第二个线程也执行(*value)++ 10000000次
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, start_routine, (void*)value);
    pthread_create(&tid2, NULL, start_routine, (void*)value);

    // 主线乘等待两个子线程结束。并打印 *value 的值。
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("*value = %lld\n", *value);
    return 0;
}
