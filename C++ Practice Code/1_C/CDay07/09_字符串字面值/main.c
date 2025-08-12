#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

char digit_to_hex_char(int digit) {
	return "0123456789ABCDEF"[digit];
}

/*
1. 书写方式
*/
int main(void) {
	// printf("I love xixi\n");
	
	//printf("I love xixi\
    // -- From peanut\n");

	// 如果两个字符串字面值之间仅有空白字符，那么这两个字符串字面“相邻”
	// C语言编译器在编译时，会将相邻的字面值拼接在一起。
	//printf("I love xixi"
	//	   "  --From peanut\n");

	// printf("   *\n");
	// printf("  * *\n");
	// ...

	//printf("   *\n"
	//	   "  * *\n"
	//	   " *   *\n");

	// 2. 存储方式
	// char* p = "Hello";
	// printf("%c\n", "Hello"[1]);
	// "Hello"[1] = 'E';

	return 0;
}