#include "blockq.h"
#include <func.h>

BlockQ* blockq_create(void) {
	BlockQ* q = (BlockQ*) malloc(sizeof(BlockQ));

	q->front = 0;
	q->rear = 0;
	q->size = 0;
	pthread_mutex_init(&q->mutex, NULL);
	pthread_cond_init(&q->not_empty, NULL);
	pthread_cond_init(&q->not_full, NULL);

	return q;
}

void blockq_destroy(BlockQ* q) {
	pthread_cond_destroy(&q->not_full);
	pthread_cond_destroy(&q->not_empty);
	pthread_mutex_destroy(&q->mutex);
	free(q);
}

bool blockq_empty(BlockQ* q) {
	pthread_mutex_lock(&q->mutex);
	int sz = q->size;
	pthread_mutex_unlock(&q->mutex);
	return sz == 0;
}

bool blockq_full(BlockQ* q) {
	pthread_mutex_lock(&q->mutex);
	int sz = q->size;
	pthread_mutex_unlock(&q->mutex);
	return sz == N;
}

void blockq_push(BlockQ* q, E val) {
	pthread_mutex_lock(&q->mutex);
	while (q->size == N) {
		// not_full条件不成立, 等待
		// 1. 释放q->mutex 
		// 2. 陷入阻塞
		pthread_cond_wait(&q->not_full, &q->mutex);
		// 3. 重新获取了q->mutex 
		// 可能存在虚假唤醒现象
		// not_full现在成不成立是不知道的，表示这个条件曾经成立过
	} // q->size != N
	
	q->elements[q->rear] = val;
	q->rear = (q->rear + 1) % N;
	q->size++;

	// 队列一定不空, not_empty 满足
	pthread_cond_signal(&q->not_empty);

	// 释放锁
	pthread_mutex_unlock(&q->mutex);
}

E blockq_pop(BlockQ* q) {
	// 上锁
	pthread_mutex_lock(&q->mutex);
	while (q->size == 0) {
		// not_empty条件不成立，等待
		pthread_cond_wait(&q->not_empty, &q->mutex);
		// 可能会存在虚假唤醒现象
	}
	// not_empty条件成立
	E val = q->elements[q->front];
	q->front = (q->front + 1) % N;
	q->size--;

	// not_full条件成立
	pthread_cond_signal(&q->not_full);
	// 释放互斥锁
	pthread_mutex_unlock(&q->mutex);

	return val;
}

E blockq_peek(BlockQ* q) {
	pthread_mutex_lock(&q->mutex);
	while (q->size == 0) {
		pthread_cond_wait(&q->not_empty, &q->mutex);
	}
	E val = q->elements[q->front];
	pthread_mutex_unlock(&q->mutex);
	return val;
}
