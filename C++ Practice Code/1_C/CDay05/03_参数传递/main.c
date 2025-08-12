#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

//void swap(int x, int y) {
//	int t = x;
//	x = y;
//	y = t;
//}

void clear(int* arr, int n) {
	for (int i = 0; i < SIZE(arr); i++) {
		arr[i] = 0;
	}
}

int main(void) {
	int arr[5] = { 1, 2, 3, 4, 5 };

	clear(arr, 5);

	for (int i = 0; i < SIZE(arr); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}