#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

// ע�����
	// a. double free
	// b. use after free
	// c. �ڴ�й©

int main(void) {
	//int* p = malloc(100 * sizeof(int));

	//for (int i = 0; i < 100; i++) {
	//	p[i] = i;
	//}

	//for (int i = 0; i < 100; i++) {
	//	*p++ = i;
	//}


	// free(p); // p��Ϊ������ָ�룬����ָ����Ұָ���һ�֡�
	// free(p);

	// *p = 10;

	int* p = malloc(100 * sizeof(int));
	int* q = malloc(100 * sizeof(int));

	p = q;

	free(p);
	free(q);
	return 0;
}