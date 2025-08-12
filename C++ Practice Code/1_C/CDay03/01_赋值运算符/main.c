#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	int i;
	float f;

	f = i = 3.14f;

	// expr1 = expr2: 值：赋值后，左边表达式expr1的值。
	//                副作用：改变左边表达式的值
	f = (i = 3.14f);

	printf("i = %d, f = %.2f\n", i, f);
	return 0;
}