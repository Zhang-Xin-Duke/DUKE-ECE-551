#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	//printf("%c\n", 'a');
	//printf("%c\n", '\141');
	//printf("%c\n", '\x61');

	//char ch;
	//int i;

	//i = 'a';				/* i is now 97 */
	//ch = 65;				/* ch is now 'A' */
	//ch = ch + 1;			/* ch is now 'B' */
	//ch++;					/* ch is now 'C' */

	//'a' / 'b' % 'c';

	//printf("%c", 'a');
	//putchar('a');

	//int i;
	//char c;

	// scanf("%d%c", &i, &c);
	// scanf("%d %c", &i, &c);
	// c = getchar();

	int length = 0;
	printf("Enter a message: ");

	while (getchar() != '\n') {
		length++;
	}

	printf("Your message was %d character(s) long.\n", length);
	return 0;
}