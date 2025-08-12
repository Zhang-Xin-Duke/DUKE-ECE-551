#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// seed --> n1 --> n2 --> n3 --> n4 --> ...

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
int roll_dices(void) {
	int a = rand() % 6 + 1;
	int b = rand() % 6 + 1;
	printf("You rolled: %d\n", a + b);
	return a + b;
}

bool play_game(void) {
	// 第一次投掷
	int point = roll_dices();
	if (point == 7 || point == 11) {
		printf("You win!\n");
		return true;
	} 
	if (point == 2 || point == 3 || point == 12) {
		printf("You lose!\n");
		return false;
	}
	// 游戏进入第二个阶段
	for (;;) {
		int tally = roll_dices();
		if (tally == point) {
			printf("You win!\n");
			return true;
		}
		if (tally == 7) {
			printf("You lose!\n");
			return false;
		}
	}
}

int main(void) {
	int wins = 0, losses = 0;

	srand(time(NULL));
	char again;
	do {
		play_game() ? wins++ : losses++;
		printf("\Play again? ");
		scanf(" %c", &again);
	} while (again == 'y' || again == 'Y');

	printf("Wins: %d Losses: %d\n", wins, losses);

	int board[8];  (i, board[i])

	return 0;
}