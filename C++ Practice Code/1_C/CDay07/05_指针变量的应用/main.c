#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE(a) (sizeof(a)/sizeof(a[0]))
/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/*
指针的应用：
	(a) 作为参数: 值传递
	(b) 作为返回值  malloc(...)
*/

//void swap(int* pa, int* pb) {
//	int t = *pa;
//	*pa = *pb;
//	*pb = t;
//}

// 正确版本
void min_max(const int* arr, int n, int* pmin, int* pmax) {
	*pmin = arr[0];
	*pmax = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] < *pmin) {
			*pmin = arr[i];
		}  else if (arr[i] > *pmax) {
			*pmax = arr[i];
		}
	}
}

//// 错误版本
//void min_max(int arr[], int n, int* pmin, int* pmax) {
//	for (int i = 1; i < n; i++) {
//		if (arr[i] < *pmin) {
//			pmin = &arr[i];
//		} else if (arr[i] > *pmax) {
//			pmax = &arr[i];
//		}
//	}
//}


int main(void) {
	int arr[] = { 0, 1, 2, 3, 4, 5, 9, 8, 7, 6 };

	int min, max;
	min_max(arr, SIZE(arr), &min, &max);

	printf("min = %d, max = %d\n", min, max);


	//int arr[] = { 0, 1, 2, 3, 4, 5, 9, 8, 7, 6 };
	//int* pmin = &arr[0];
	//int* pmax = &arr[0];

	//min_max(arr, SIZE(arr), pmin, pmax);

	//printf("*pmin = %d\n", *pmin);
	//printf("*pmax = %d\n", *pmax);

	return 0;
}

