#include <stdio.h>

#define SIZE(a) (sizeof(a) / sizeof(a[0]))


int binary_search(int arr[], int n, int key) {
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

/**********************************************************************/
/*                  查找第一个与key值相等的元素                         */
/**********************************************************************/
// 总结：
// 除以2^n：  >> n
// 乘以2^n:   << n
// 对2^3取余：& 0x7
int binary_search1(int arr[], int n, int key) {
	// 闭区间
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left >> 1);
		// 比较
		int cmp = key - arr[mid];
		if (cmp < 0) {
			right = mid - 1;
		} else if (cmp > 0) {
			left = mid + 1;
		} else {
			// cmp == 0
			// 如果arr[mid]是第一个和key值相等的元素
			if (mid == left || arr[mid - 1] < key) {
				return mid;
			}
			right = mid - 1;
		}
	}
}

/**********************************************************************/
/*                  查找第一个大于等于key值的元素                         */
/**********************************************************************/
int binary_search2(int arr[], int n, int key) {
	// 闭区间
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left >> 1);
		// 比较
		int cmp = arr[mid] - key;

		if (cmp < 0) {
			left = mid + 1;
		} else {
			// cmp >= 0
			// 如果arr[mid]是第一个大于等于key值的元素
			if (mid == left || arr[mid-1] < key) {
				return mid;
			}
			right = mid - 1;
		}
	}  // left > right
	return -1;
}

/****************************************************************************/
/*                    查询循环有序数组的最小元素                              */
/****************************************************************************/

int findMin(int arr[], int n) {
	int left = 0, right = n - 1;

	while (left < right) {
		// 通过一次比较，丢掉不包含最小值的区间
		int mid = left + (right - left >> 1);	// 如果区间长度为2, mid == left
		// 和 arr[right]比较
		int cmp = arr[mid] - arr[right];
		if (cmp > 0) {
			left = mid + 1;
		} else {
			right = mid;
		}

	} // left == right

	return arr[left];
}

int main(void) {
	int arr[] = { 0, 10, 20, 30, 30, 30, 30, 30, 30, 40, 50, 60, 70, 80, 90 };

	// int idx = binary_search1(arr, SIZE(arr), 30);
	int idx1 = binary_search2(arr, SIZE(arr), -100);  // 0
	int idx2 = binary_search2(arr, SIZE(arr), 30);    // 3
	int idx3 = binary_search2(arr, SIZE(arr), 15);    // 2
	int idx4 = binary_search2(arr, SIZE(arr), 9527);  // -1


	return 0;
}