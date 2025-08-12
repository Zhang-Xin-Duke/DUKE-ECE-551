#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// 搜索头文件的路径：系统的include目录下搜索
#include "Vector.h" // 搜索头文件的路径：当前目录 --> 系统的include目录下搜索

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/*
单元测试
*/
int main(void) {
	Vector* v = vector_create();	// 创建空的动态数组

	for (int i = 1; i <= 100; i++) {
		push_back(v, i * 10);
	}

	for (int i = 0; i < v->size; i++) {
		printf("%d ", v->elements[i]);
	}
	printf("\n");

	vector_destroy(v);
	return 0;
}