#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

//void foo(void) {
//	static int a = 1;
//	printf("&a = %p, a = %d\n", &a, a++);
//	foo();
//}

long long next_fib(void) {
	static long long a = 0;
	static long long b = 1;

	int t = a + b;
	a = b;
	b = t;

	return a;
}

int main(void) {
	// FibnacciÊýÁÐ£º0, 1, 1, 2, 3, 5, 8, 13, ...

	printf("%lld\n", next_fib());	// 1
	printf("%lld\n", next_fib());	// 1
	printf("%lld\n", next_fib());	// 2
	printf("%lld\n", next_fib());	// 3
	printf("%lld\n", next_fib());	// 5

	return 0;
}