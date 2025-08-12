#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

//long long fib(int n) {
//	if (n == 0 || n == 1) return n;
//	return fib(n - 2) + fib(n - 1);
//}

long long fib(int n) {
	if (n == 0 || n == 1) return n;
	// n >=2
	int a = 0, b = 1;

	// 循环不变式：每次进入循环体之前(那一刻)，都保持的性质。
	//            fib(i)未求解
	for (int i = 2; i <= n; i++) {
		int t = a + b; // 计算fib(i)
		a = b;
		b = t;         // 将fib(i)保存到变量b中
	}
	// i == n+1, 循环不变式会保持到循环的结束，fib(i)未求解
	return b;
}

int main(void) {
	// 0, 1, 1, 2, 3, 5, 8, 13, 21
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	printf("fib(%d) = %lld\n", n, fib(n));
	return 0;
}