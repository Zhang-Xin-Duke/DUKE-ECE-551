#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

// 创建空的栈
Stack* stack_create(void) {
	return calloc(1, sizeof(Stack));
}

void  stack_destroy(Stack* stack) {
	// 先释放一个一个结点
	Node* curr = stack->top;
	while (curr) {
		Node* next = curr->next;
		free(curr);
		curr = next;	// Use after free
	} // curr == NULL

	// 再释放Stack结构体
	free(stack);
}

void stack_push(Stack* stack, E val) {
	// 头插法
	// 1. 创建并初始化结点
	Node* new_node = malloc(sizeof(Node));
	new_node->data = val;
	new_node->next = stack->top;

	// 2. 修改整个栈的信息
	stack->top = new_node;
	stack->size++;
}

E stack_pop(Stack* stack) {
	if (stack_empty(stack)) {
		printf("Error: Stack EMPTY!\n");
		exit(1);
	}
	
	Node* remove_node = stack->top;
	E retval = remove_node->data;

	stack->top = remove_node->next;
	stack->size--;
	free(remove_node);

	return retval;
}

E stack_peek(const Stack* stack) {
	if (stack_empty(stack)) {
		printf("Error: Stack EMPTY!\n");
		exit(1);
	}

	return stack->top->data;
}

bool stack_empty(const Stack* stack) {
	return stack->size == 0;
}