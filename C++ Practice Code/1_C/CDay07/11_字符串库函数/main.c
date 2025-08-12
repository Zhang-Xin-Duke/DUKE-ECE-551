#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

size_t my_strlen(const char* s) {
	//size_t len = 0;
	//while (*s != '\0') {
	//	len++;
	//	s++;
	//} // *s == '\0';
	//return len;

	const char* p = s;
	while (*p) {	// p不指向空字符
		p++;
	} // *p == '\0'
	return p - s;

	//const char* p = s;
	//while (*p++) {	 // *p++ --> *p
	//} // p指向空字符的后面

	return p - s;
}

int main(void) {
	// a. size_t strlen(const char* s)

	//printf("strlen(\"abc\") = %d\n", strlen("abc"));
	//printf("strlen(\"\") = %d\n", strlen(""));

	printf("my_strlen(\"abc\") = %d\n", my_strlen("abc"));
	printf("my_strlen(\"\") = %d\n", my_strlen(""));



	return 0;
}