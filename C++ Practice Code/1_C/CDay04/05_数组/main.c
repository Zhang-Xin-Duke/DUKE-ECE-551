#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// a��һ������
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {

	//int arr[5];  // ��������arr;  ���ͣ�int[5]

	//int arr1[5];  // �����˳���Ϊ5��int���飬û�г�ʼ��
	//int arr2[5] = { 1, 2, 3, 4, 5 }; // ��ʼ��ʽ
	//int arr3[5] = { 1, 2, 3 };
	//int arr4[] = { 1, 2, 3, 4, 5 };

	// 2. ������ȡ�±�[]
	//int arr[] = { 1, 2, 3, 4, 5 };
	//
	//printf("arr[3] = %d\n", arr[3]);
	//// C���Բ���������Ƿ�Խ�磬����Խ����һ��"δ������Ϊ"��
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

	// 5. �ñ�������������ĳ���
	int arr[1];

	return 0;
}