#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

// 注意事项：
	// a. double free
	// b. use after free
	// c. 内存泄漏

int main(void) {
	//int* p = malloc(100 * sizeof(int));

	//for (int i = 0; i < 100; i++) {
	//	p[i] = i;
	//}

	//for (int i = 0; i < 100; i++) {
	//	*p++ = i;
	//}


	// free(p); // p成为了悬空指针，悬空指针是野指针的一种。
	// free(p);

	// *p = 10;

	int* p = malloc(100 * sizeof(int));
	int* q = malloc(100 * sizeof(int));

	p = q;

	free(p);
	free(q);
	return 0;
}