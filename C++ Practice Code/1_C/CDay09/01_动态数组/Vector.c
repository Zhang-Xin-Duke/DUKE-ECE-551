// 动态数组的实现
#include "Vector.h"
#include <stdlib.h>

#define DEFAULT_CAPACITY  8
#define MAX_PREALLOC   1024

// 创建一个空的动态数组
Vector* vector_create(void) {
	Vector* v = malloc(sizeof(Vector));

	//if (v == NULL) {
	//	printf("Error: malloc failed\n");
	//	exit(1);
	//}
	
	if (!v) { // 如果v (指向的对象) 不存在
		printf("Error: malloc failed\n");
		exit(1);
	}
	
	v->elements = malloc(DEFAULT_CAPACITY * sizeof(E));
	if (!v->elements) {
		free(v);
		printf("Error: malloc failed\n");
		exit(1);
	}

	v->size = 0;
	v->capacity = DEFAULT_CAPACITY;

	return v;
}


void vector_destroy(Vector* v) {
	// 按申请的相反顺序释放资源
	free(v->elements);
	free(v);
}

void grow_capacity(Vector* v) {
	// 扩容策略
	int new_capacity = (v->capacity < MAX_PREALLOC) ?
		(v->capacity << 1) : (v->capacity + MAX_PREALLOC);

	/* WRONG: realloc 失败返回NULL, 并且旧内存块不会被释放！ */
	E* p = realloc(v->elements, new_capacity * sizeof(E));
	if (!p) {
		printf("Error: realloc failed\n");
		exit(1);
	}

	v->elements = p; 
	v->capacity = new_capacity;
}

// 请实现push_back方法
void push_back(Vector* v, E val) {
	if (v->size == v->capacity) {
		grow_capacity(v);
	}
	// 容量肯定够大，添加元素
	v->elements[v->size] = val;
	v->size++;
}