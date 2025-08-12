#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

#define SWAP(arr, i, j) {	\
	int t = arr[i];			\
	arr[i] = arr[j];		\
	arr[j] = t;				\
}

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

void insertion_sort(int arr[], int n);
void shell_sort(int arr[], int n);
void merge_sort(int arr[], int n);
// int partition1(int arr[], int left, int right);
// int partition2(int arr[], int left, int right);
void quick_sort(int arr[], int n);
void heap_sort(int arr[], int n);

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void) {
	int arr[] = { 6, 5, 2, 7, 1, 3, 9, 0, 8 ,4 };
	print_array(arr, SIZE(arr));

	// insertion_sort(arr, SIZE(arr));
	// shell_sort(arr, SIZE(arr));
	// merge_sort(arr, SIZE(arr));

	// int idx = partition1(arr, 0, 9);
	// int idx = partition2(arr, 0, 9);

	// quick_sort(arr, SIZE(arr));
	heap_sort(arr, SIZE(arr));

	// print_array(arr, SIZE(arr));
	return 0;
}

/*******************************************************************/
/*                         插入排序                                 */
/*******************************************************************/
void insertion_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int value = arr[i];		// 插入arr[i]这个元素

		int j = i - 1;
		while (j >= 0 && arr[j] > value) {
			arr[j + 1] = arr[j];
			j--;
		} // j == -1 || arr[j] <= value

		arr[j + 1] = value;

		// 调试信息
		print_array(arr, n);
	}
}

/*******************************************************************/
/*                         希尔排序                                 */
/*******************************************************************/
void shell_sort(int arr[], int n) {
	int gap = n >> 1;
	while (gap) {
		// 组间插入排序
		for (int i = gap; i < n; i++) { // i: 牌堆的第一张牌
			int value = arr[i];
			// 在手牌中，从后往前找
			int j = i - gap;
			while (j >= 0 && arr[j] > value) {
				arr[j + gap] = arr[j];
				j -= gap;
			} // j < 0 || arr[j] <= value
			arr[j + gap] = value;
		}

		// 调试信息
		print_array(arr, n);
		// 缩小gap
		gap >>= 1;
	} // gap == 0
}

/*******************************************************************/
/*                         归并排序                                 */
/*******************************************************************/
int tmp[10];

void merge(int arr[], int left, int mid, int right) { // O(n)
	// 左区间：[left, mid]
	// 右区间：[mid+1, right]
	int i = left, j = mid + 1, k = left;
	// a. 两个区间都有元素
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) { // Caution: 一定要写成 <=
			tmp[k++] = arr[i++];
		} else {
			tmp[k++] = arr[j++];
		}
	} // i > mid || j > right
	// b. 如果左边区间还有元素
	while (i <= mid) {
		tmp[k++] = arr[i++];
	}
	// c. 如果右边区间还有元素
	while (j <= right) {
		tmp[k++] = arr[j++];
	}
	// 复制
	for (int k = left; k <= right; k++) {
		arr[k] = tmp[k];
	}
}


void m_sort(int arr[], int left, int right) {
	// 闭区间 [left, right]
	// 1. 边界条件
	if (left >= right) return;
	// 2. 递归公式
	// int mid = (left + right) / 2;	// 如果int只占两个字节，可能发生溢出
	int mid = left + (right - left >> 1);
	// 对左边区间排序
	m_sort(arr, left, mid);
	// 对右边区间排序
	m_sort(arr, mid + 1, right);
	// 归并
	merge(arr, left, mid, right);

	// 调试信息
	print_array(arr, 10);
}

void merge_sort(int arr[], int n) {
	// 闭区间：[0, n-1]
	m_sort(arr, 0, n - 1);
}

/*******************************************************************/
/*                         快速排序                                 */
/*******************************************************************/
// a. 单向分区
int partition1(int arr[], int left, int right) {
	// 闭区间[left, right]
	int pivot = arr[right];		// 基准值
	int s = left;   // 下一个小于等于pivot的元素应该置于的位置
	for (int i = left; i < right; i++) {
		if (arr[i] <= pivot) {
			SWAP(arr, s, i);
			s++;
		}
	}
	// 交换s和right位置的两个元素
	SWAP(arr, s, right);

	return s; // 最终基准值所在的位置
}

// b. 双向分区
int partition2(int arr[], int left, int right) {
	int pivot = arr[left];	// 选取基准值
	
	int i = left, j = right;
	while (i < j) {
		while (i < j && arr[j] >= pivot) {
			j--;
		} // i == j || arr[j] < pivot
		arr[i] = arr[j];

		while (i < j && arr[i] <= pivot) {
			i++;
		} // i == j || arr[i] > pivot
		arr[j] = arr[i];
	} // i == j
	arr[i] = pivot;
	return i; // 最终基准值位于的位置
}

void q_sort(int arr[], int left, int right) {
	// 闭区间：[left, right]
	// 1. 边界条件
	if (left >= right) return;
	// 2. 递归公式
	// 分区
	int idx = partition2(arr, left, right);
	// [left, idx) <= idx <= (idx, right]
	// 调试信息
	print_array(arr, 10);
	
	// 对左边区间排序
	q_sort(arr, left, idx - 1);
	// 对右边区间排序
	q_sort(arr, idx + 1, right);
}

void quick_sort(int arr[], int n) {
	// 闭区间：[0, n-1]
	q_sort(arr, 0, n - 1);
}

/*******************************************************************/
/*                         堆排序                                   */
/*******************************************************************/
// arr: 数组
// i: 根结点的索引
// len: 堆的范围
// 前提：i的左子树和右子树都是大顶堆
void heapify(int arr[], int i, int len) {  // O(log n)
	while (i < len) {
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;

		int maxIdx = i;		// 认为根结点i最大
		if (lchild < len && arr[lchild] > arr[maxIdx]) {
			maxIdx = lchild;
		}
		if (rchild < len && arr[rchild] > arr[maxIdx]) {
			maxIdx = rchild;
		}

		if (maxIdx == i) break;	  // 根结点最大，退出！

		SWAP(arr, i, maxIdx);
		i = maxIdx;
	}
}

void build_heap(int arr[], int n) {
	// 从后往前找第一个非叶子结点
	// lchild(i) = 2i + 1 <= n-1
	// i <= (n-2)/2
	for (int i = (n - 2 >> 1); i >= 0; i--) {
		heapify(arr, i, n);
	}
}

void heap_sort(int arr[], int n) {
	// 1. 构建大顶堆
	build_heap(arr, n);

	// 调试信息
	print_array(arr, n);

	// 2. 排序
	int len = n;	// 无序区的长度
	while (len > 1) {
		// 交换堆顶元素和无序区的最后一个元素
		SWAP(arr, 0, len - 1);
		// 无序区的长度减1
		len--;

		// 调试信息
		print_array(arr, n);

		// 将无序区重新调整成大顶堆
		heapify(arr, 0, len);
	} // len == 1
}