#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/* WRONG: ����ָ��ǰջ֡ (foo) ��ָ����� */
int* foo(void) {
	int i = 3;
	// ...
	return &i;
}

/* ��ȷ��*/
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