#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

// 两种方式：
// （1）int *p = &i;
//  (2) int *p = &i;
//      int *q = p;
//  (3) int *p = NULL;
int main(void) {

	int i = 3, j = 4;
	int* p = &i;
	int* q = &j;

	printf("i = %d, j = %d\n", i, j);		// 3,4
	printf("*p = %d, *q = %d\n", *p, *q);	// 3,4

	// p = q;
	*p = *q;

	printf("i = %d, j = %d\n", i, j);		// 4,4
	printf("*p = %d, *q = %d\n", *p, *q);   // 4,4

	return 0;
}