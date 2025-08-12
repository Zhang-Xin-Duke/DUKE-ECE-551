#pragma once

#include <stdbool.h>
// 类型的定义和API

typedef int E;

// 结点的信息
typedef struct node {
	E data;
	struct node* next;
} Node;

// 整个栈的信息
typedef struct {
	Node* top;
	int size;
} Stack;

// typedef Node* Stack;  不要这么做！

// API
Stack* stack_create(void);
void  stack_destroy(Stack* stack);

void stack_push(Stack* stack, E val);
E stack_pop(Stack* stack);
E stack_peek(const Stack* stack);
bool stack_empty(const Stack* stack);
