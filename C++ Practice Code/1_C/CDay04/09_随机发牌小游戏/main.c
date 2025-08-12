#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/*
1. 如何表示一张牌？
	静态属性 (属性)：花色、大小
	动态属性 (方法)：
	const char suits[4] = {'d', 'c', 'h', 's'};
	      d: diamond 钻石 
		  c: club    梅花
		  h: heart   红心
		  s: spade   黑桃
	const char ranks[13] = {'2', '3', ..., 'T', 'J', 'Q', 'K', 'A'};
	(i, j) = (3, 4) = 6s

2. 如何随机发牌？
   伪随机数

3. 如何判重?
	bool in_hand[4][13] = { false };
	bool in_deck[4][13] = { true };   WRONG !
*/
int main(void) {

	// seed --> num1 --> num2 --> num3 --> ...

	// time_t t = time(NULL);
	// printf("%u\n", (unsigned)t);

	srand(time(NULL));		// 设置随机种子，一般随机种子只需要设置依次
	printf("%d\n", rand());
	// srand(100);
	printf("%d\n", rand());
	// srand(100);
	printf("%d\n", rand());

	return 0;
}