#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(arr, i, j) {	\
	int t = arr[i];			\
	arr[i] = arr[j];		\
	arr[j] = t;				\
}

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

void shuffle(int arr[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n - 1; i++) {
		// ��[i, n-1]�����ѡ��һ��Ԫ�أ��ŵ�i��λ��
		int r = rand() % (n - i) + i; 
		SWAP(arr, i, r);
	}
}

int main(void) {
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	shuffle(arr, 10);
	return 0;
}

