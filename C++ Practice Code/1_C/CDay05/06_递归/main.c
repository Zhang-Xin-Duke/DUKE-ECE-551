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

	// ѭ������ʽ��ÿ�ν���ѭ����֮ǰ(��һ��)�������ֵ����ʡ�
	//            fib(i)δ���
	for (int i = 2; i <= n; i++) {
		int t = a + b; // ����fib(i)
		a = b;
		b = t;         // ��fib(i)���浽����b��
	}
	// i == n+1, ѭ������ʽ�ᱣ�ֵ�ѭ���Ľ�����fib(i)δ���
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