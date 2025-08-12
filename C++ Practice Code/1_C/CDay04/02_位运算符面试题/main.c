#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int last_set_bit(int n) {
	// 思路一
	//int lsb = 0x1; // 1, 2, 4, 8, ...
	//while ((n & lsb) == 0) {
	//	lsb <<= 1;
	//} // (n & lsb) != 0
	//return lsb;

	// 思路二
	return n & -n;
}

int main(void) {
	/*int a = 3, b = 4;
	printf("a = %d, b = %d\n", a, b);*/
	// 交换a和b的值
	//int t = a;
	//a = b;
	//b = t;
	
	// 利用一对逆运算，来交换两个数 a0, b0
	//a = a + b; // a1 = a0 + b0, b1 = b0
	//b = a - b; // a2 = a0 + b0, b2 = a1 - b1 = a0
	//a = a - b; // a3 = a2 - b2 = b0, b3 =a0
	
	// 逆运算：^ 和 ^,   a ^ b ^ b = a
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


	// 6. 找两个单独的数
	int nums[] = { 1, 2, 1, 3, 2, 5 };

	int xor = 0; // exclusive-or
	for (int i = 0; i < 6; i++) {
		xor ^= nums[i];
	}
	// xor = a ^ b;   (a,b不同，xor != 0)
	// 找出 xor 值为1的位 （last set bit）, a，b在这一位的值不同
	int lsb = xor & -xor;  // 2的幂
	
	// 根据这一位 (lsb)，将所有元素分类
	int a = 0, b = 0;
	for (int i = 0; i < 6; i++) {
		if (nums[i] & lsb) {
			// 为1
			a ^= nums[i];
		} else {
			// 为0
			b ^= nums[i];
		}
	}

	printf("a = %d, b = %d\n", a, b);

	return 0;
}