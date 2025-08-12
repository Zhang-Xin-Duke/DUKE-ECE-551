#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define DEFAULT_CAPACITY  8
#define MAX_CAPACITY   4096

// 创建空的队列
Queue* queue_create(void) {
	Queue* q = calloc(1, sizeof(Queue));
	q->elements = malloc(DEFAULT_CAPACITY * sizeof(E));
	q->capacity = DEFAULT_CAPACITY;
	return q;
}

void queue_destroy(Queue* q) {
	free(q->elements);
	free(q);
}

void grow_capacity(Queue* q) {
	int new_capacity = q->capacity << 1;
	E* new_arr = realloc(q->elements, new_capacity * sizeof(E));
	if (!new_arr) {
		printf("Error: realloc failed\n");
		exit(1);
	}
	q->elements = new_arr;
	// 将[0,front)迁移到[old_capacity, old_capacity + front)
	for (int i = 0; i < q->front; i++) {
		q->elements[q->capacity + i] = q->elements[i];
	}
	q->capacity = new_capacity;
	q->rear = q->front + q->size;
}

void queue_push(Queue* q, E val) {
	if (queue_full(q)) {
		printf("Error: Queue FULL!\n");
		exit(1);
	}
	// 判断是否需要扩容
	if (q->size == q->capacity) {
		grow_capacity(q);
	}
	q->elements[q->rear] = val;
	q->rear = (q->rear + 1) % q->capacity;
	q->size++;
}

E queue_pop(Queue* q) {
	if (queue_empty(q)) {
		printf("Error: Queue EMPTY!\n");
		exit(1);
	}
	E retval = q->elements[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	return retval;
}

E queue_peek(const Queue* q) {
	if (queue_empty(q)) {
		printf("Error: Queue EMPTY!\n");
		exit(1);
	}
	return q->elements[q->front];
}

bool queue_empty(const Queue* q) {
	return q->size == 0;
}

bool queue_full(const Queue* q) {
	return q->size == MAX_CAPACITY;
}