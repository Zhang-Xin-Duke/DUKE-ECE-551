#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	// expr1 ? expr2 : expr3
	// 1. 计算expr1的值
	// 2. a.如果expr1的值为真，计算expr2的值，并把expr2的值作为整个表达式的值。 (expr3不计算)
	//    b.如果expr1的值为假，计算expr3的值，并把expr3的值作为整个表达式的值。 (expr2不计算)

	int i, j, k;

	i = 1;
	j = 2;
	k = i > j ? i : j;			// i=1, j=2, k=2
	k = i > j ? i++ : j++;		// i=1, j=3, k=2
	k = (i >= 0 ? i : 0) + j;   // i=1, j=3, k=4
	return 0;
}