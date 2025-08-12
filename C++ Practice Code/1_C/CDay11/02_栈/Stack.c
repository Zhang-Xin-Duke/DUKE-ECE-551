#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

// �����յ�ջ
Stack* stack_create(void) {
	return calloc(1, sizeof(Stack));
}

void  stack_destroy(Stack* stack) {
	// ���ͷ�һ��һ�����
	Node* curr = stack->top;
	while (curr) {
		Node* next = curr->next;
		free(curr);
		curr = next;	// Use after free
	} // curr == NULL

	// ���ͷ�Stack�ṹ��
	free(stack);
}

void stack_push(Stack* stack, E val) {
	// ͷ�巨
	// 1. ��������ʼ�����
	Node* new_node = malloc(sizeof(Node));
	new_node->data = val;
	new_node->next = stack->top;

	// 2. �޸�����ջ����Ϣ
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