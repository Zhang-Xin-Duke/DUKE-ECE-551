#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

// long long steps = 0;

void hanoi(int n, char start, char middle, char target) {
	// 1. �߽�����
	if (n == 1) {
		printf("%c --> %c\n", start, target);
		// steps++;
		return;
	}
	// 2. �ݹ��ϵ
	// ��n-1�����ӣ���start����target�ƶ���middle��
	hanoi(n - 1, start, target, middle);
	// ������������ӣ���start�ƶ���target
	printf("%c --> %c\n", start, target);
	// steps++;
	// ��n-1�����ӣ���middle����start�ƶ���target��
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