#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/*
ö�� 
���ã���ʾһЩ��ɢֵ (�˿��ƵĻ�ɫ��״̬�����)

ö��ֵ��������

*/

//#define DIAMOND 0
//#define CLUB	1
//#define HEART	2
//#define SPADE	3
//
//typedef int Suit;

// ����ö������
typedef enum {
	// ����ö��ֵ
	DIAMOND = 1, CLUB = 2, HEART = 4, SPADE = 8
} Suit;

int main(void) {
	Suit s1 = DIAMOND;
	Suit s2 = CLUB;
	Suit s3 = HEART;
	Suit s4 = SPADE;

	return 0;
}