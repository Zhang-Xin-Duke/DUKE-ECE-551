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
/*                         ��������                                 */
/*******************************************************************/
void insertion_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int value = arr[i];		// ����arr[i]���Ԫ��

		int j = i - 1;
		while (j >= 0 && arr[j] > value) {
			arr[j + 1] = arr[j];
			j--;
		} // j == -1 || arr[j] <= value

		arr[j + 1] = value;

		// ������Ϣ
		print_array(arr, n);
	}
}

/*******************************************************************/
/*                         ϣ������                                 */
/*******************************************************************/
void shell_sort(int arr[], int n) {
	int gap = n >> 1;
	while (gap) {
		// ����������
		for (int i = gap; i < n; i++) { // i: �ƶѵĵ�һ����
			int value = arr[i];
			// �������У��Ӻ���ǰ��
			int j = i - gap;
			while (j >= 0 && arr[j] > value) {
				arr[j + gap] = arr[j];
				j -= gap;
			} // j < 0 || arr[j] <= value
			arr[j + gap] = value;
		}

		// ������Ϣ
		print_array(arr, n);
		// ��Сgap
		gap >>= 1;
	} // gap == 0
}

/*******************************************************************/
/*                         �鲢����                                 */
/*******************************************************************/
int tmp[10];

void merge(int arr[], int left, int mid, int right) { // O(n)
	// �����䣺[left, mid]
	// �����䣺[mid+1, right]
	int i = left, j = mid + 1, k = left;
	// a. �������䶼��Ԫ��
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) { // Caution: һ��Ҫд�� <=
			tmp[k++] = arr[i++];
		} else {
			tmp[k++] = arr[j++];
		}
	} // i > mid || j > right
	// b. ���������仹��Ԫ��
	while (i <= mid) {
		tmp[k++] = arr[i++];
	}
	// c. ����ұ����仹��Ԫ��
	while (j <= right) {
		tmp[k++] = arr[j++];
	}
	// ����
	for (int k = left; k <= right; k++) {
		arr[k] = tmp[k];
	}
}


void m_sort(int arr[], int left, int right) {
	// ������ [left, right]
	// 1. �߽�����
	if (left >= right) return;
	// 2. �ݹ鹫ʽ
	// int mid = (left + right) / 2;	// ���intֻռ�����ֽڣ����ܷ������
	int mid = left + (right - left >> 1);
	// �������������
	m_sort(arr, left, mid);
	// ���ұ���������
	m_sort(arr, mid + 1, right);
	// �鲢
	merge(arr, left, mid, right);

	// ������Ϣ
	print_array(arr, 10);
}

void merge_sort(int arr[], int n) {
	// �����䣺[0, n-1]
	m_sort(arr, 0, n - 1);
}

/*******************************************************************/
/*                         ��������                                 */
/*******************************************************************/
// a. �������
int partition1(int arr[], int left, int right) {
	// ������[left, right]
	int pivot = arr[right];		// ��׼ֵ
	int s = left;   // ��һ��С�ڵ���pivot��Ԫ��Ӧ�����ڵ�λ��
	for (int i = left; i < right; i++) {
		if (arr[i] <= pivot) {
			SWAP(arr, s, i);
			s++;
		}
	}
	// ����s��rightλ�õ�����Ԫ��
	SWAP(arr, s, right);

	return s; // ���ջ�׼ֵ���ڵ�λ��
}

// b. ˫�����
int partition2(int arr[], int left, int right) {
	int pivot = arr[left];	// ѡȡ��׼ֵ
	
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
	return i; // ���ջ�׼ֵλ�ڵ�λ��
}

void q_sort(int arr[], int left, int right) {
	// �����䣺[left, right]
	// 1. �߽�����
	if (left >= right) return;
	// 2. �ݹ鹫ʽ
	// ����
	int idx = partition2(arr, left, right);
	// [left, idx) <= idx <= (idx, right]
	// ������Ϣ
	print_array(arr, 10);
	
	// �������������
	q_sort(arr, left, idx - 1);
	// ���ұ���������
	q_sort(arr, idx + 1, right);
}

void quick_sort(int arr[], int n) {
	// �����䣺[0, n-1]
	q_sort(arr, 0, n - 1);
}

/*******************************************************************/
/*                         ������                                   */
/*******************************************************************/
// arr: ����
// i: ����������
// len: �ѵķ�Χ
// ǰ�᣺i�������������������Ǵ󶥶�
void heapify(int arr[], int i, int len) {  // O(log n)
	while (i < len) {
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;

		int maxIdx = i;		// ��Ϊ�����i���
		if (lchild < len && arr[lchild] > arr[maxIdx]) {
			maxIdx = lchild;
		}
		if (rchild < len && arr[rchild] > arr[maxIdx]) {
			maxIdx = rchild;
		}

		if (maxIdx == i) break;	  // ���������˳���

		SWAP(arr, i, maxIdx);
		i = maxIdx;
	}
}

void build_heap(int arr[], int n) {
	// �Ӻ���ǰ�ҵ�һ����Ҷ�ӽ��
	// lchild(i) = 2i + 1 <= n-1
	// i <= (n-2)/2
	for (int i = (n - 2 >> 1); i >= 0; i--) {
		heapify(arr, i, n);
	}
}

void heap_sort(int arr[], int n) {
	// 1. �����󶥶�
	build_heap(arr, n);

	// ������Ϣ
	print_array(arr, n);

	// 2. ����
	int len = n;	// �������ĳ���
	while (len > 1) {
		// �����Ѷ�Ԫ�غ������������һ��Ԫ��
		SWAP(arr, 0, len - 1);
		// �������ĳ��ȼ�1
		len--;

		// ������Ϣ
		print_array(arr, n);

		// �����������µ����ɴ󶥶�
		heapify(arr, 0, len);
	} // len == 1
}