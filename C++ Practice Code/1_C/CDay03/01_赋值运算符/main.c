#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	int i;
	float f;

	f = i = 3.14f;

	// expr1 = expr2: ֵ����ֵ����߱��ʽexpr1��ֵ��
	//                �����ã��ı���߱��ʽ��ֵ
	f = (i = 3.14f);

	printf("i = %d, f = %.2f\n", i, f);
	return 0;
}