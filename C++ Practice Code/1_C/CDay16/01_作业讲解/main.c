#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

#define SWAP(arr, i, j) {	\
	int t = arr[i];			\
	arr[i] = arr[j];		\
	arr[j] = t;				\
}

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
void selection_sort(int arr[], int n);
void bubble_sort(int arr[], int n);

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void) {
	int arr[] = { 9, 5, 2, 7, 1, 3, 4, 0, 8, 6 };

	print_array(arr, SIZE(arr));

	// selection_sort(arr, SIZE(arr));
	bubble_sort(arr, SIZE(arr));
	return 0;
}

void selection_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		// i: 未排序区最小元素应该置于的位置
		int minIdx = i;
		// 遍历未排序区，找到最小元素
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}
		// 将最小元素交换到i的位置
		SWAP(arr, i, minIdx);

		// 调试信息
		print_array(arr, n);
	}
}

void bubble_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		// i: 第i次冒泡
		bool sorted = true;
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > arr[j + 1]) {
				// 逆序对
				SWAP(arr, j, j + 1);
				sorted = false;
			}
		}

		if (sorted) break;
		print_array(arr, n);
	}
}