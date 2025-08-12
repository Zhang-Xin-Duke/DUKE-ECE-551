#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

//void is_prime(int n) {
//	int i = 2;
//	for (; i * i <= n; i++) {
//		if (n % i == 0) {
//			break;
//		}
//	}
//	
//	if (i * i > n) {
//		printf("Prime\n");
//	} else {
//		printf("Not prime\n");
//	}
//}


/*
�ͺ�����ص��﷨�ṹ��

bool is_prime(int n);			��������
bool is_prime(int n) {...}		�������� (��������)
is_prime(34);					��������
bool flag = is_prime(19);		��������
is_prime;						����ָ�� (���潲)

*/

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	if (is_prime(n)) {
		printf("Prime\n");
	} else {
		printf("Not prime\n");
	}

	return 0;
}