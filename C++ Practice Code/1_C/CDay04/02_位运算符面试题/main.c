#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int last_set_bit(int n) {
	// ˼·һ
	//int lsb = 0x1; // 1, 2, 4, 8, ...
	//while ((n & lsb) == 0) {
	//	lsb <<= 1;
	//} // (n & lsb) != 0
	//return lsb;

	// ˼·��
	return n & -n;
}

int main(void) {
	/*int a = 3, b = 4;
	printf("a = %d, b = %d\n", a, b);*/
	// ����a��b��ֵ
	//int t = a;
	//a = b;
	//b = t;
	
	// ����һ�������㣬������������ a0, b0
	//a = a + b; // a1 = a0 + b0, b1 = b0
	//b = a - b; // a2 = a0 + b0, b2 = a1 - b1 = a0
	//a = a - b; // a3 = a2 - b2 = b0, b3 =a0
	
	// �����㣺^ �� ^,   a ^ b ^ b = a
	//a = a ^ b;
	//b = a ^ b;
	//a = a ^ b;

	//printf("a = %d, b = %d\n", a, b);


	//int nums[] = {1, 4, 2, 1, 2};

	//int singleNum = 0;     // x ^ 1 ^ 4 ^ 2 ^ 1 ^ 2;
	//for (int i = 0; i < 5; i++) {
	//	singleNum ^= nums[i];
	//}

	//printf("singleNum = %d\n", singleNum);


	// 6. ��������������
	int nums[] = { 1, 2, 1, 3, 2, 5 };

	int xor = 0; // exclusive-or
	for (int i = 0; i < 6; i++) {
		xor ^= nums[i];
	}
	// xor = a ^ b;   (a,b��ͬ��xor != 0)
	// �ҳ� xor ֵΪ1��λ ��last set bit��, a��b����һλ��ֵ��ͬ
	int lsb = xor & -xor;  // 2����
	
	// ������һλ (lsb)��������Ԫ�ط���
	int a = 0, b = 0;
	for (int i = 0; i < 6; i++) {
		if (nums[i] & lsb) {
			// Ϊ1
			a ^= nums[i];
		} else {
			// Ϊ0
			b ^= nums[i];
		}
	}

	printf("a = %d, b = %d\n", a, b);

	return 0;
}