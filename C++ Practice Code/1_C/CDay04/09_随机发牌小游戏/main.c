#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/*
1. ��α�ʾһ���ƣ�
	��̬���� (����)����ɫ����С
	��̬���� (����)��
	const char suits[4] = {'d', 'c', 'h', 's'};
	      d: diamond ��ʯ 
		  c: club    ÷��
		  h: heart   ����
		  s: spade   ����
	const char ranks[13] = {'2', '3', ..., 'T', 'J', 'Q', 'K', 'A'};
	(i, j) = (3, 4) = 6s

2. ���������ƣ�
   α�����

3. �������?
	bool in_hand[4][13] = { false };
	bool in_deck[4][13] = { true };   WRONG !
*/
int main(void) {

	// seed --> num1 --> num2 --> num3 --> ...

	// time_t t = time(NULL);
	// printf("%u\n", (unsigned)t);

	srand(time(NULL));		// ����������ӣ�һ���������ֻ��Ҫ��������
	printf("%d\n", rand());
	// srand(100);
	printf("%d\n", rand());
	// srand(100);
	printf("%d\n", rand());

	return 0;
}