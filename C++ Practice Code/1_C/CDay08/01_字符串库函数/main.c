#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define N 100
/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

//char* my_strcpy(char* s1, const char* s2) {
//	char* start = s1;
//
//	while (*s2) {
//		*s1 = *s2;
//		s1++;
//		s2++;
//	} // *s2 == '\0'
//
//	*s1 = '\0';	// 以空字符结尾
//	return start;
//}

char* my_strcpy(char* s1, const char* s2) {
	char* start = s1;

	// 惯用法：字符串的复制
	while (*s1++ = *s2++)
		;
	
	return start;
}


char* my_strcat(char* s1, const char* s2) {
	char* start = s1;

	// 1. 找s1的末尾，遍历s1
	while (*s1) {
		s1++;
	} // s1指向空字符

	// 2. 复制s2
	while (*s1++ = *s2++)
		;

	return start;
}

int my_strcmp(const char* s1, const char* s2) {
	while (*s1 && *s2) {
		if (*s1 != *s2) {
			return *s1 - *s2;
		}
		s1++;
		s2++;
	} 
	// *s1 == '\0' || *s2 =='\0'
	return *s1 - *s2;
}


int main(void) {
	// "abc" + 1;
	// 1. char* strcat(char* s1, const char* s2);	// 不会检查数组是否越界
	// strcat: string + concatenate

	// char s1[] = "Hello";
	//char s1[N] = "Hello";
	//printf("%s\n", strcat(s1, " xixi"));

	// strncat(char* s1, const char* s2, size_t maxCount);
	// maxCount: 可以拼接的最大字符数目

	//char s1[10] = "Hello";
	//strncat(s1, " world", sizeof(s1) - strlen(s1) - 1);
	//s1[sizeof(s1) - 1] = '\0';

	// 2. char* strcpy(char* s1, const char* s2); // 弊端：不会检查数组越界

	//char s1[10] = "Hello";
	//char* s2 = "world world";
	//// strcpy(s1, s2);
	//strncpy(s1, s2, sizeof(s1) - 1);
	//s1[sizeof(s1) - 1] = '\0';

	//printf("s1: %s\n", s1);

	// 3. int strcmp(const char* s1, const char* s2);  
	// s1 = s2: 返回 0
	// s1 < s2: 返回负数
	// s1 > s2: 返回整数

	// 比较规则：字典序(ASCII)

	printf("my_strcmp(\"CBA\", \"NBA\") = %d\n", my_strcmp("CBA", "NBA"));   // <0
	printf("my_strcmp(\"CBA\", \"NBA\") = %d\n", my_strcmp("CBA", "CBAC"));  // <0
	printf("my_strcmp(\"CBA\", \"NBA\") = %d\n", my_strcmp("CBA", "cba"));   // <0

	return 0;
}