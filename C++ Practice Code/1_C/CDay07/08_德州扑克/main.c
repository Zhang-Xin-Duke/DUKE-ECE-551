#include <stdio.h>
#include <stdbool.h>

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int num_in_rank[13];
int num_in_suit[4];

bool straight, flush, four, three;
int pairs;	/* can be 0, 1, or 2 */

int main(void) {
	for (;; ) {
		read_cards();
		analyze_hand();
		print_result();
	}

	return 0;
}

void print_result(void) {
	if (straight && flush) {
		printf("Straight flush\n");
	} else if (four) {
		printf("Four\n");
	} else if (three && (pairs == 1)) {
		printf("Full hourse\n");
	} else if (flush) {
		printf("Flush\n");
	} else if (straight) {
		printf("Straight\n");
	} else if (three && (pairs == 0)) {
		printf("Three\n");
	} else if (pairs == 2) {
		printf("Two pairs\n");
	} else if (pairs == 1) {
		printf("One pair\n");
	} else {
		printf("High card\n");
	}
	printf("\n");
}

void analyze_hand(void) {
	/* 初始化 */
	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;

	/* 检查是否为同花 */
	for (int i = 0; i < 4; i++) {
		if (num_in_suit[i] == 5) {
			flush = true;
		}
	}

	/* 检查是否为顺子 */
	int idx = 0;
	while (num_in_rank[idx] == 0) {
		idx++;
	}
	// num_in_rank[idx] != 0;
	int n_consective = 0;
	while (idx < 13 && num_in_rank[idx] != 0) {
		n_consective++;
		idx++;
	}  // idx >= 13 || num_in_rank[idx] == 0

	if (n_consective == 5) {
		straight = true;
		return;
	}

	/* 判断四张，三张，两张 */
	for (int i = 0; i < 13; i++) {
		if (num_in_rank[i] == 4) {
			four = true;
		} else if (num_in_rank[i] == 3) {
			three = true;
		} else if (num_in_rank[i] == 2) {
			pairs++;
		}
	}
}

void read_cards(void) {
	// 初始化操作
	bool in_hand[4][13] = { false };

	for (int i = 0; i < 13; i++) {
		num_in_rank[i] = 0;
	}
	for (int i = 0; i < 4; i++) {
		num_in_suit[i] = 0;
	}

	// 读取5张卡牌
	int cards_read = 0;
	while (cards_read < 5) {
		bool bad_card = false;

		printf("Enter a card: ");

		char c = getchar();
		int rank;
		switch (c) {
		case '0':			exit(0);
		case '2':			rank = 0;	break;
		case '3':			rank = 1;	break;
		case '4':			rank = 2;	break;
		case '5':			rank = 3;	break;
		case '6':			rank = 4;	break;
		case '7':			rank = 5;	break;
		case '8':			rank = 6;	break;
		case '9':			rank = 7;	break;
		case 't':case 'T':	rank = 8;	break;
		case 'j':case 'J':	rank = 9;	break;
		case 'q':case 'Q':	rank = 10;	break;
		case 'k':case 'K':	rank = 11;	break;
		case 'a':case 'A':	rank = 12;	break;
		default:			bad_card = true;
		}

		c = getchar();
		int suit;
		switch (c) {
		case 'd':case 'D':	suit = 0;	break;
		case 'c':case 'C':	suit = 1;	break;
		case 'h':case 'H':	suit = 2;	break;
		case 's':case 'S':	suit = 3;	break;
		default:			bad_card = true;
		}

		// 处理这一行的剩余字符
		while ((c = getchar()) != '\n') {
			if (c != ' ' && c != '\t')
				bad_card = true;
		}

		if (bad_card) {
			printf("Bad card; ignored.\n");
		} else if (in_hand[suit][rank]) {
			printf("Duplicate card; ignored.\n");
		} else {
			in_hand[suit][rank] = true;
			cards_read++;
			num_in_rank[rank]++;
			num_in_suit[suit]++;
		}
	}
}