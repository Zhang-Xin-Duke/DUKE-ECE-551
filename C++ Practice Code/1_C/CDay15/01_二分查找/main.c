#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/


/**********************************************************************/
/*                          递归实现                                   */
/**********************************************************************/

int b_search(int arr[], int left, int right, int key) {
	// 闭区间：[left, right]
	// 1. 边界条件
	if (left > right) return -1;
	// 2. 递归公式
	int mid = left + (right - left >> 1);   // 计算中间元素的索引
	int cmp = key - arr[mid];	// 比较
	
	if (cmp < 0) {
		return b_search(arr, left, mid - 1, key);
	}
	if (cmp > 0) {
		return b_search(arr, mid + 1, right, key);
	}
	// cmp == 0
	return mid;
}

int binary_search1(int arr[], int n, int key) {
	return b_search(arr, 0, n - 1, key);
}

/**********************************************************************/
/*                          循环实现 (模板)                            */
/**********************************************************************/

int binary_search2(int arr[], int n, int key) {
	// 闭区间：[left, right]
	int left = 0, right = n - 1;

	while (left <= right) {		// Caution1: left <= right
		int mid = left + (right - left >> 1);  // Caution2: 避免溢出
		// 比较
		int cmp = key - arr[mid];
		if (cmp < 0) {
			right = mid - 1;	// Caution3: right = mid - 1;
		} else if (cmp > 0) {
			left = mid + 1;		// Caution3: left = mid + 1;
		} else {
			return mid;
		}
	} // left > right
	return -1;
}

// DevOps
int main(void) {
	
	int arr[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	// int idx1 = binary_search2(arr, SIZE(arr), 30);	  // 3
	int idx2 = binary_search2(arr, SIZE(arr), 9527);  // -1
	return 0;
}