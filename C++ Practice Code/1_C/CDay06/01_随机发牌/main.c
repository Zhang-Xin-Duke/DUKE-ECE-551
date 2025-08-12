#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	const char suits[] = { 'D', 'C', 'H', 'S' };
	const char ranks[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
	bool in_hand[4][13] = { false };

	int cards;
	printf("Enter number of cards in hand: ");
	scanf("%d", &cards);

	// 随机发牌
	srand(time(NULL));
	while (cards) {
		int i = rand() % 4;
		int j = rand() % 13;
		if (!in_hand[i][j]) {
			cards--;
			in_hand[i][j] = true; // 标记这张牌 (i, j) 已经发过了
			printf("%c%c ", ranks[j], suits[i]);
		}
	} // cards == 0
	printf("\n");

	return 0;
}