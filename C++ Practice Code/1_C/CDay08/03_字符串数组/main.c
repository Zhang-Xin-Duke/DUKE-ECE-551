#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
/*
�ַ������飺
	a. ��ά�ַ�����
	   char planets[][8] =  {	"Mercury", "Venus", "Earth", "Mars", 
                      	"Jupiter", "Saturn", "Uranus", "Neptune" };
	   �׶ˣ�
	      1�������˷��ڴ�ռ�
		  2) ����� (����)

	b. �ַ�ָ������ (�Ƽ�)
		char* planets[] =  {"Mercury", "Venus", "Earth", "Mars", 
                    "Jupiter", "Saturn", "Uranus", "Neptune"};
		�ô���
			�ǳ����
*/

/* 
�����в�����������ϵͳ���ݸ�main�����Ĳ�����
	argc: argument count
	argv: argument vector

	�����в��������ַ���:
		argv[0]: ��ִ�г��������
*/
int main(int argc, char* argv[]) {
	//for (int i = 0; i < argc; i++) {
	//	puts(argv[i]);
	//}

	// ����ת��
	int i;		// argv[1]
	double d;	// argv[2]

	if (argc < 3) {
		printf("Error!\n");
		exit(1);
	}

	sscanf(argv[1], "%d", &i);
	sscanf(argv[2], "%lf", &d);

	return 0;
}