#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/*
C语言是面向过程(函数)的语言：
	函数是C语言程序的基本构建单位：C语言程序是由函数之间的相互调用组成的
*/

int roll_dices(void);

bool play_game(void);

int main(void) {
	int wins = 0, losses = 0;
	char again;
	do {
		play_game() ? wins++ : losses++;

		printf("\nPlay again? ");
		// ...
	} while (again == 'y' || again == 'Y');

	printf("Wins: %d Losses: %d\n", wins, losses);

	return 0;
}