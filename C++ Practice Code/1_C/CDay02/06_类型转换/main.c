#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	//char c = '1';
	//short s = 10;
	//int i = 100;
	//long l = 1000L;
	//long long ll = 10000LL;
	//float f = 3.14f;
	//double d = 2.67;

	//int i = -1;
	//unsigned u = 100;

	//if (i > u) {
	//	printf("xixi loves me\n");
	//}


	// 显示转换
	// 1. 计算浮点数的小数部分
	double d = 3.14;
	double fraction = d - (int)d;
	// 2. 注释作用
	int i;
	float f = 6.17f;
	// ...
	i = (int)f; // 注意：这里发生了强制类型转换，可能会丢失精度。
	// 3. 精确控制类型转换
	int dividend = 7, divisor = 4;
	double quotient = (double)dividend / divisor;
	// 4. 避免发生溢出
	long long millis_per_day = 24 * 60 * 60 * 1000;
	long long nanos_per_day = (long long)24 * 60 * 60 * 1000 * 1000 * 1000;
	printf("nanos_per_day / millis_per_day = %lld\n", nanos_per_day / millis_per_day);

	return 0;
}