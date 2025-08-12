#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	//int i = 10;
	//float f = 3.14f;
	//printf("i = %d, f = %f\n", i, f);

	//int i = 1234;
	//printf("|%d|%2d|%6d|%-6d|\n", i, i, i, i);

	//int i = 123;
	//float f = 3.1415926;
	//printf("|%.2d|%.4d|%.6d|\n", i, i, i);
	//printf("|%.2f|%.4f|%.6f|\n", f, f, f);

	int i = 40;
	float x = 839.21f;

	printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
	printf("|%f|%10f|%10.2f|%-10.2f|\n", x, x, x, x);

	return 0;
}