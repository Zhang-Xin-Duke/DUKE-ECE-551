#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	//int i = 1;
	//// ++i: 值：原来的i加1
	////  副作用：i自增
	//printf("i is %d\n", ++i);	// 2
	//printf("i is %d\n", i);		// 2


	int i = 1;
	// i++: 值：原来的i
	//  副作用：i自增
	printf("i is %d\n", i++);	// 1
	printf("i is %d\n", i);		// 2
	return 0;
}