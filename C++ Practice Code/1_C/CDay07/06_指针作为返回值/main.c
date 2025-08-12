#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/* WRONG: 返回指向当前栈帧 (foo) 的指针变量 */
int* foo(void) {
	int i = 3;
	// ...
	return &i;
}

/* 正确的*/
int* find_middle(int arr[], int n) {
	return &arr[n / 2];
}

int main(void) {
	//int* p = foo();
	//printf("*p = %d\n", *p);
	//printf("*p = %d\n", *p);

	int arr[] = { 1, 2, 3, 4, 5 };
	int* p = find_middle(arr, 5);

	printf("*p = %d\n", *p);
	printf("*p = %d\n", *p);
	return 0;
}