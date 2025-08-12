#pragma once

#include <stdbool.h>
// ���͵Ķ����API

typedef int E;

// ������Ϣ
typedef struct node {
	E data;
	struct node* next;
} Node;

// ����ջ����Ϣ
typedef struct {
	Node* top;
	int size;
} Stack;

// typedef Node* Stack;  ��Ҫ��ô����

// API
Stack* stack_create(void);
void  stack_destroy(Stack* stack);

void stack_push(Stack* stack, E val);
E stack_pop(Stack* stack);
E stack_peek(const Stack* stack);
bool stack_empty(const Stack* stack);
