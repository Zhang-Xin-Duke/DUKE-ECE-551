#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

// long long steps = 0;

void hanoi(int n, char start, char middle, char target) {
	// 1. 边界条件
	if (n == 1) {
		printf("%c --> %c\n", start, target);
		// steps++;
		return;
	}
	// 2. 递归关系
	// 将n-1个盘子，从start经过target移动到middle上
	hanoi(n - 1, start, target, middle);
	// 将最下面的盘子，从start移动到target
	printf("%c --> %c\n", start, target);
	// steps++;
	// 将n-1个盘子，从middle经过start移动到target上
	hanoi(n - 1, middle, start, target);
}

int main(void) {
	int n;
	scanf("%d", &n);
	long long steps = (1LL << n) - 1; // 2^n - 1

	printf("total step(s): %lld\n", steps);
	hanoi(n, 'A', 'B', 'C');
	
	return 0;
}