#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SWAP(a, b) {		\
	int t = a;				\
	a = b;					\
	b = t;					\
}							
/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
// 1. gcd(a, 0) = a （a !=0 ）
// 2. gcd(a, b) = gcd(b, r)    a = b * q + r (r >= 0, r < b)
//    令 x = gcd(a, b), x = gcd(b * q + r, b), x能整除b和r
//    令 y = gcd(b, r) > x, y能整除b * q + r 和 b, 这与 x是b*q+r和b的最大公约数矛盾。
//    因此 gcd(a,b) = gcd(b,r)

// gcd(a, b) = gcd(b, r) = ... gcd(x, 0) = x

int gcd(int a, int b) {
	if (a < b) {
		SWAP(a, b);
	}

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	} // b == 0

	return a;
}


int main(void) {

	int num1 = 0;
	int denom1 = 0;
	printf(" Enter the first fraction:");
	scanf("%d/%d", &num1, &denom1);


	int num2 = 0;
	int denom2 = 0;
	printf(" Enter the second fraction:");
	scanf("%d/%d", &num2, &denom2);

	int result_num = num1 * denom2 + num2 * denom1;
	int result_denom = denom1 * denom2;

	int divisor = gcd(result_num, result_denom);
	result_num /= divisor;
	result_denom /= divisor;

	if (divisor == result_denom) {
		printf("the sum is %d", result_num / divisor);
	} else {
		printf("the sum is %d/%d", result_num, result_denom);
	}

	return 0;
}
