#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
// 空指针：不指向任何对象的指针。一般用NULL(0)表示空指针
//		  不能对空指针进行解引用

// void*： 通用指针类型 (不知道基类型是什么).
//        特性：可以和其它类型的指针相互转换 (隐式转换)
//        不能对通用指针类型的变量解引用
int main(void) {

	// int* p = malloc(sizeof(int) * 1000);    /* malloc = memory + allocate */
	void* p = calloc(1000, sizeof(int));		   /* calloc = clear + allocate */

	// printf("%d\n", *p);
	return 0;
}