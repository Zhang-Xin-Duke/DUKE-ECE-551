#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {

	//int* p = &i;
	//printf("*p = %d\n", *p);
	//*p = 4;

	//int i = 3, j = 4;
	//const int* p = &i;

	//printf("p = 0x%p\n", p);
	//p = &j;
	//printf("*p = %d\n", *p);	
	// *p = 4;	

	//i = 30;
	//printf("*p = %d\n", *p);

	//int i = 3, j = 4;
	//int* const p = &i;

	//printf("p = 0x%p\n", p);
	//// p = &j;
	//printf("*p = %d\n", *p);
	//*p = 4;


	int i = 3, j = 4;
	const int* const p = &i;

	printf("p = 0x%p\n", p);
	// p = &j;
	printf("*p = %d\n", *p);
	// *p = 4;



	return 0;
}