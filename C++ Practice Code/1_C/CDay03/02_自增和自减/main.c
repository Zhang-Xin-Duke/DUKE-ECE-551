#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	//int i = 1;
	//// ++i: ֵ��ԭ����i��1
	////  �����ã�i����
	//printf("i is %d\n", ++i);	// 2
	//printf("i is %d\n", i);		// 2


	int i = 1;
	// i++: ֵ��ԭ����i
	//  �����ã�i����
	printf("i is %d\n", i++);	// 1
	printf("i is %d\n", i);		// 2
	return 0;
}