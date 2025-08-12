#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

bool is_odd(int n) {
	/* WRONG: C语言中余数可能是负数，余数的符号和被除数的符号一致 */
	// return n % 2 == 1;

	// return n % 2 != 0;
	// 补码：奇数的最低位一定是1
	// mask 掩码操作：&
	return n & 0x1;
}

//bool is_power_of_2(int n) { // n > 0
//	while (n & 0x1 == 0) {
//		n >>= 1;
//	}
//	return n == 1;
//}

bool is_power_of_2(int n) { 
	// 2的幂的二进制表示有什么特点：只有一位为1
	/*
	n:  0101 0000        0100 0000
	n-1:0100 1111        0011 1111
	*/
	return (n & n - 1) == 0;
}

int main(void) {
	int i = -1;	// -1是奇数
	printf("is_odd(%d) = %s\n", i, is_odd(i) ? "true" : "false");
	return 0;
}