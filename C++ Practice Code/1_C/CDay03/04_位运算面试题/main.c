#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

bool is_odd(int n) {
	/* WRONG: C���������������Ǹ����������ķ��źͱ������ķ���һ�� */
	// return n % 2 == 1;

	// return n % 2 != 0;
	// ���룺���������λһ����1
	// mask ���������&
	return n & 0x1;
}

//bool is_power_of_2(int n) { // n > 0
//	while (n & 0x1 == 0) {
//		n >>= 1;
//	}
//	return n == 1;
//}

bool is_power_of_2(int n) { 
	// 2���ݵĶ����Ʊ�ʾ��ʲô�ص㣺ֻ��һλΪ1
	/*
	n:  0101 0000        0100 0000
	n-1:0100 1111        0011 1111
	*/
	return (n & n - 1) == 0;
}

int main(void) {
	int i = -1;	// -1������
	printf("is_odd(%d) = %s\n", i, is_odd(i) ? "true" : "false");
	return 0;
}