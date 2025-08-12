#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	int i = 3;
	int* p = &i;

	printf("*p = %d\n", *p);	// *p = 3

	*p = 4;

	printf("i = %d\n", i);		// i = 4;

	return 0;
}