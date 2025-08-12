#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

//void is_prime(int n) {
//	int i = 2;
//	for (; i * i <= n; i++) {
//		if (n % i == 0) {
//			break;
//		}
//	}
//	
//	if (i * i > n) {
//		printf("Prime\n");
//	} else {
//		printf("Not prime\n");
//	}
//}


/*
和函数相关的语法结构：

bool is_prime(int n);			函数声明
bool is_prime(int n) {...}		函数定义 (包含声明)
is_prime(34);					函数调用
bool flag = is_prime(19);		函数调用
is_prime;						函数指针 (后面讲)

*/

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);

	if (is_prime(n)) {
		printf("Prime\n");
	} else {
		printf("Not prime\n");
	}

	return 0;
}