#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define N 8
/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int solutions = 0;

void print_board(int board[]) {
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (board[row] == col) {
				printf("Q ");
			} else {
				printf(". ");
			}
		}
		printf("\n");
	}
	printf("\n");
}

bool is_safe(int board[], int row, int col) {
	for (int i = 0; i < row; i++) {
		// 1. 在同一列
		if (board[i] == col) {
			return false;
		}
		// 2. 在主对角线上
		if (board[i] - i == col - row) {
			return false;
		}
		// 3. 在副对角线上
		if (board[i] + i == col + row) {
			return false;
		}
	}
	return true;
}

void solve_queues(int board[], int row) {
	// 1. 边界条件
	if (row == N) {
		print_board(board);
		solutions++;
		return;
	}
	for (int col = 0; col < N; col++) {
		if (is_safe(board, row, col)) {
			// 在 (row, col)位置放置一个皇后
			board[row] = col;
			solve_queues(board, row + 1);
			// 回溯
			board[row] = -1;
		}
	}
}

int main(void) {
	int board[N];
	for (int i = 0; i < N; i++) {
		board[i] = -1;
	}

	solve_queues(board, 0);

	printf("total solution(s): %d\n", solutions);
	return 0;
}