#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/*
外部变量：定义在所有函数外面的变量。又称全局变量。
	作用域：文件作用域。从变量定义开始，到文件的末尾。
	存储期间：静态存储期间。与"天地同寿"

问题：static的局部变量和外部变量有什么区别？
	作用域不同

Tips: 尽量避免使用外部变量，不利于程序的维护和Debug.

*/
void foo(void);
void bar(void);

int main(void) {
	// printf("a = %d, b = %d\n", a, b);
	foo();
	bar();
	return 0;
}


int a = 3, b = 4;

void foo(void) {
	printf("a = %d, b = %d\n", a, b);
}

void bar(void) {
	printf("a = %d, b = %d\n", a, b);
}