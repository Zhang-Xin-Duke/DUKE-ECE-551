#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void) {
	for (;;) {
		read_cards();	// 提取你需要的信息
		analyze_hand();
		print_result();
	}
	return 0;
}

int num_in_suit[4];		// 记录每一种花色有多少张
int num_in_rank[13];	// 记录每一个点数有多少张

void read_cards(void) {
	// 清空数组
	for (int i = 0; i < 4; i++) {
		num_in_suit[i] = 0;
	}
	for (int i = 0; i < 13; i++) {
		num_in_rank[i] = 0;
	}

	bool in_hand[4][13] = { false };
	
	int cards = 0;
	while (cards < 5) {
		printf("Enter a card: ");

		bool bad_card = false;

		char c = getchar();
		int rank;
		switch (c) {
		case '0':				exit(0);
		case '2':				rank = 0; break;
			// ...
		case 't': case 'T':		rank = 8; break;
			// ...
		default:				bad_card = true; break;
		}

		c = getchar();
		int suit;
		switch (c) {
		case 'd': case 'D':		suit = 0; break;
			// ...
		default:				bad_card = true; break;
		}

		// (suit, rank)
		if (bad_card) {
			printf("Bad card; ignored.\n");
		} else if (in_hand[suit][rank]) {
			printf("Duplicate card; ignored.\n");
		} else {
			cards++;
			in_hand[suit][rank] = true;
			num_in_suit[suit]++;
			num_in_rank[rank]++;
		}
	}
}

bool flush, straight, four, three;
int pairs;	/* Can be 0, 1, 2 */

void analyze_hand(void) {
	// 数据的转换
}


void print_result(void) {

}