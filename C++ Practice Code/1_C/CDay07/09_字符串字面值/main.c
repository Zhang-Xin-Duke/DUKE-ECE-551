#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

char digit_to_hex_char(int digit) {
	return "0123456789ABCDEF"[digit];
}

/*
1. ��д��ʽ
*/
int main(void) {
	// printf("I love xixi\n");
	
	//printf("I love xixi\
    // -- From peanut\n");

	// ��������ַ�������ֵ֮����пհ��ַ�����ô�������ַ������桰���ڡ�
	// C���Ա������ڱ���ʱ���Ὣ���ڵ�����ֵƴ����һ��
	//printf("I love xixi"
	//	   "  --From peanut\n");

	// printf("   *\n");
	// printf("  * *\n");
	// ...

	//printf("   *\n"
	//	   "  * *\n"
	//	   " *   *\n");

	// 2. �洢��ʽ
	// char* p = "Hello";
	// printf("%c\n", "Hello"[1]);
	// "Hello"[1] = 'E';

	return 0;
}