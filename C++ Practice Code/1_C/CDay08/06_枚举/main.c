#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/*
枚举 
作用：表示一些离散值 (扑克牌的花色、状态、类别)

枚举值是整数！

*/

//#define DIAMOND 0
//#define CLUB	1
//#define HEART	2
//#define SPADE	3
//
//typedef int Suit;

// 定义枚举类型
typedef enum {
	// 罗列枚举值
	DIAMOND = 1, CLUB = 2, HEART = 4, SPADE = 8
} Suit;

int main(void) {
	Suit s1 = DIAMOND;
	Suit s2 = CLUB;
	Suit s3 = HEART;
	Suit s4 = SPADE;

	return 0;
}