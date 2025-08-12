#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {

	Stack* stack = stack_create();

	stack_push(stack, 1);
	stack_push(stack, 2);
	stack_push(stack, 3);
	stack_push(stack, 4);

	// ±éÀúÕ»
	while (!stack_empty(stack)) {
		E val = stack_peek(stack);
		printf("%d ", val);
		stack_pop(stack);
	}
	printf("\n");   
	// 4 --> 3 --> 2 --> 1

	stack_destroy(stack);

	return 0;
}