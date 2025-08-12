#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	int num1, denom1;
	printf("Enter first fraction: ");
	scanf("%d/%d", &num1, &denom1);

	int num2, denom2;
	printf("Enter second fraction: ");
	scanf("%d/%d", &num2, &denom2);

	// º∆À„
	int result_num = num1 * denom2 + num2 * denom1;
	int result_denom = denom1 * denom2;

	printf("The sum is %d/%d\n", result_num, result_denom);
	return 0;
}