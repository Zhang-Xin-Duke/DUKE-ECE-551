#include <func.h>
#include "blockq.h"

typedef struct {
	pthread_t* threads;
	int num;
	BlockQ* q;
} ThreadPool;

void* start_routine(void* arg) {
	ThreadPool* pool = (ThreadPool*)arg;

	pthread_t tid = pthread_self();
	for(;;) {
		int task_id = blockq_pop(pool->q);
		if (task_id == -1) {
			// 退出
			printf("0x%lx: exit\n", tid);
			pthread_exit(NULL);
		}
		printf("0x%lx: execute task %d\n", tid, task_id);
		sleep(3);	// 模拟执行任务
		printf("0x%lx: task %d done\n", tid, task_id);
	}

	return NULL;
}

ThreadPool* threadpool_create(int n) {
	ThreadPool* pool = (ThreadPool*)malloc(sizeof(ThreadPool));

	pool->threads = (pthread_t*) malloc(n * sizeof(pthread_t)); // 保存线程的ID
	pool->num = n;
	pool->q = blockq_create();

	// 创建线程
	for(int i = 0; i < n; i++) {
		pthread_create(pool->threads + i, NULL, start_routine, (void*)pool);
	}
	return pool;
}

void threadpool_destroy(ThreadPool* pool) {
	blockq_destroy(pool->q);
	free(pool->threads);
	free(pool);
}

int main(int argc, char* argv[])
{
	// 创建线程池
	ThreadPool* pool = threadpool_create(8);

	// 往阻塞队列中添加任务
	for (int i = 1; i <= 100; i++) {
		blockq_push(pool->q, i);
	}

	sleep(10);
	
	// 退出
	// 1. 暴力退出
	/* for (int i = 0; i < pool->num; i++) { */
	/* 	pthread_cancel(pool->threads[i]); // 发送取消请求 */
	/* } */
	// 2. 有序退出 (优雅的退出)
	for (int i = 0; i < pool->num; i++) {
		blockq_push(pool->q, -1); // task_id == -1
	}

	for(int i = 0; i < pool->num; i++) {
		pthread_join(pool->threads[i], NULL); // 等待线程池中线程结束
	}
	threadpool_destroy(pool);
    return 0;
}

