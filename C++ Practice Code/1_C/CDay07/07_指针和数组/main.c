#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int sum_array(int* arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		// arr[i] = *(arr + i) = *(i + arr) = i[arr]
		// sum += arr[i]; 
		sum += i[arr];
	}
	return sum;
}

int main(void) {
	//int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int* p = &arr[2];
	//int* q = &arr[8];

	//q = p + 3;	// +3: 向右偏移3个元素
	//
	//p += 6;

	//printf("p = 0x%p\n", p);
	//printf("q = 0x%p\n", q);

	//printf("p - q = %d\n", p - q); // -6, p在q的左边，偏移6个单位
	//printf("q - p = %d\n", q - p); // 6， q在p的右边，偏移6个单位


	// int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// 1. &arr[10] 是否会发生数组越界？
	// 不会！只是计算地址值，不会访问那片内存空间。

	// 2. 在早前的C语言程序中，经常利用指针处理数组。
	// 指针：next_addr = p + 4;
	// 下标：next_addr = base_addr + i * 4
	//int sum = 0;
	//for (int* p = &arr[0]; p < &arr[10]; p++) {
	//	sum += *p;
	//}

	//for (int i = 0; i < 10; i++) {
	//	sum += arr[i];
	//}

	//int sum = 0;
	//for (int* p = arr; p < arr + 10; p++) {
	//	sum += *p;
	//}

	// int sum = sum_array(arr, 10);

	// printf("sum = %d\n", sum);


	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int sum = 0;
	int* p = arr;

	while (p < arr + 10) {
		sum += *p++;
	}

	printf("sum = %d\n", sum);

	return 0;
}