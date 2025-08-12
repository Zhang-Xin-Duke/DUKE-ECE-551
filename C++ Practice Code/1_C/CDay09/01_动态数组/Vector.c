// ��̬�����ʵ��
#include "Vector.h"
#include <stdlib.h>

#define DEFAULT_CAPACITY  8
#define MAX_PREALLOC   1024

// ����һ���յĶ�̬����
Vector* vector_create(void) {
	Vector* v = malloc(sizeof(Vector));

	//if (v == NULL) {
	//	printf("Error: malloc failed\n");
	//	exit(1);
	//}
	
	if (!v) { // ���v (ָ��Ķ���) ������
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
	// ��������෴˳���ͷ���Դ
	free(v->elements);
	free(v);
}

void grow_capacity(Vector* v) {
	// ���ݲ���
	int new_capacity = (v->capacity < MAX_PREALLOC) ?
		(v->capacity << 1) : (v->capacity + MAX_PREALLOC);

	/* WRONG: realloc ʧ�ܷ���NULL, ���Ҿ��ڴ�鲻�ᱻ�ͷţ� */
	E* p = realloc(v->elements, new_capacity * sizeof(E));
	if (!p) {
		printf("Error: realloc failed\n");
		exit(1);
	}

	v->elements = p; 
	v->capacity = new_capacity;
}

// ��ʵ��push_back����
void push_back(Vector* v, E val) {
	if (v->size == v->capacity) {
		grow_capacity(v);
	}
	// �����϶��������Ԫ��
	v->elements[v->size] = val;
	v->size++;
}