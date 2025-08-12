#include <stdio.h>

#define SIZE(a) (sizeof(a) / sizeof(a[0]))


int binary_search(int arr[], int n, int key) {
	// �����䣺[left, right]
	int left = 0, right = n - 1;

	while (left <= right) {		// Caution1: left <= right
		int mid = left + (right - left >> 1);  // Caution2: �������
		// �Ƚ�
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
/*                  ���ҵ�һ����keyֵ��ȵ�Ԫ��                         */
/**********************************************************************/
// �ܽ᣺
// ����2^n��  >> n
// ����2^n:   << n
// ��2^3ȡ�ࣺ& 0x7
int binary_search1(int arr[], int n, int key) {
	// ������
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left >> 1);
		// �Ƚ�
		int cmp = key - arr[mid];
		if (cmp < 0) {
			right = mid - 1;
		} else if (cmp > 0) {
			left = mid + 1;
		} else {
			// cmp == 0
			// ���arr[mid]�ǵ�һ����keyֵ��ȵ�Ԫ��
			if (mid == left || arr[mid - 1] < key) {
				return mid;
			}
			right = mid - 1;
		}
	}
}

/**********************************************************************/
/*                  ���ҵ�һ�����ڵ���keyֵ��Ԫ��                         */
/**********************************************************************/
int binary_search2(int arr[], int n, int key) {
	// ������
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left >> 1);
		// �Ƚ�
		int cmp = arr[mid] - key;

		if (cmp < 0) {
			left = mid + 1;
		} else {
			// cmp >= 0
			// ���arr[mid]�ǵ�һ�����ڵ���keyֵ��Ԫ��
			if (mid == left || arr[mid-1] < key) {
				return mid;
			}
			right = mid - 1;
		}
	}  // left > right
	return -1;
}

/****************************************************************************/
/*                    ��ѯѭ�������������СԪ��                              */
/****************************************************************************/

int findMin(int arr[], int n) {
	int left = 0, right = n - 1;

	while (left < right) {
		// ͨ��һ�αȽϣ�������������Сֵ������
		int mid = left + (right - left >> 1);	// ������䳤��Ϊ2, mid == left
		// �� arr[right]�Ƚ�
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