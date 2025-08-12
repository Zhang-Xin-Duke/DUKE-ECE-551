#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	//char arr[] = { 'H', 'E', 'L', '\0', 'L', 'O', '\n', 'W', 'O', '\0' };
	//printf("arr的长度：%d\n", SIZE(arr));
	//printf("字符串的长度: %d\n", strlen(arr));

	// 1. 字符串的定义和初始化
	// char s1[] = { 'H', 'E', 'L', 'L', 'O', '\0' }; // 可读性太差
	// char s2[] = "HELLO";	// 语法糖，它是数组初始化式{ 'H', 'E', 'L', 'L', 'O', '\0' }的简写形式

	//char s1[] = "HELLO";
	//char* s2 = "HELLO";

	//s1[0] = 'h';
	//// s2[0] = 'h';

	//printf("s1: %s\n", s1);
	//printf("s2: %s\n", s2);

	char s1[] = { 'H', 'E', 'L', 'L', 'O', '\0' };
	char s2[] = "HELLO";	// 推荐1
	char s3[10] = "HELLO";	// 推荐2
	char s4[6] = "HELLO";
	char s5[5] = "HELLO";	// 不表示字符串!

	printf("s5: %s\n", s5);

	// 2. 字符串变量的操作
	// a. 字符数组支持的操作，字符串都支持。 取下标[]
	// b. <string.h> 定义了很多库函数 -- 扩展字符串类型的操作


	return 0;
}