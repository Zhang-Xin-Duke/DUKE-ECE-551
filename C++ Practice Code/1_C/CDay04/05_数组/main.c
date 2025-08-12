#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// a是一个数组
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {

	//int arr[5];  // 变量名：arr;  类型：int[5]

	//int arr1[5];  // 定义了长度为5的int数组，没有初始化
	//int arr2[5] = { 1, 2, 3, 4, 5 }; // 初始化式
	//int arr3[5] = { 1, 2, 3 };
	//int arr4[] = { 1, 2, 3, 4, 5 };

	// 2. 操作：取下标[]
	//int arr[] = { 1, 2, 3, 4, 5 };
	//
	//printf("arr[3] = %d\n", arr[3]);
	//// C语言不检查数组是否越界，数组越界是一个"未定义行为"。
	//printf("arr[5] = %d\n", arr[5]);
	//printf("arr[5000] = %d\n", arr[5000]);

	int arr[5];
	for (int i = 0; i < SIZE(arr); i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < SIZE(arr); i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');

	// 5. 让编译器计算数组的长度
	int arr[1];

	return 0;
}