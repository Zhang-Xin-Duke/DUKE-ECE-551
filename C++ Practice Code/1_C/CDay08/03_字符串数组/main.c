#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
/*
字符串数组：
	a. 二维字符数组
	   char planets[][8] =  {	"Mercury", "Venus", "Earth", "Mars", 
                      	"Jupiter", "Saturn", "Uranus", "Neptune" };
	   弊端：
	      1）可能浪费内存空间
		  2) 不灵活 (排序)

	b. 字符指针数组 (推荐)
		char* planets[] =  {"Mercury", "Venus", "Earth", "Mars", 
                    "Jupiter", "Saturn", "Uranus", "Neptune"};
		好处：
			非常灵活
*/

/* 
命令行参数：（操作系统传递给main函数的参数）
	argc: argument count
	argv: argument vector

	命令行参数都是字符串:
		argv[0]: 可执行程序的名字
*/
int main(int argc, char* argv[]) {
	//for (int i = 0; i < argc; i++) {
	//	puts(argv[i]);
	//}

	// 参数转换
	int i;		// argv[1]
	double d;	// argv[2]

	if (argc < 3) {
		printf("Error!\n");
		exit(1);
	}

	sscanf(argv[1], "%d", &i);
	sscanf(argv[2], "%lf", &d);

	return 0;
}