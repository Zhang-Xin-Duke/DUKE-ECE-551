#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(void) {
	//char arr[] = { 'H', 'E', 'L', '\0', 'L', 'O', '\n', 'W', 'O', '\0' };
	//printf("arr�ĳ��ȣ�%d\n", SIZE(arr));
	//printf("�ַ����ĳ���: %d\n", strlen(arr));

	// 1. �ַ����Ķ���ͳ�ʼ��
	// char s1[] = { 'H', 'E', 'L', 'L', 'O', '\0' }; // �ɶ���̫��
	// char s2[] = "HELLO";	// �﷨�ǣ����������ʼ��ʽ{ 'H', 'E', 'L', 'L', 'O', '\0' }�ļ�д��ʽ

	//char s1[] = "HELLO";
	//char* s2 = "HELLO";

	//s1[0] = 'h';
	//// s2[0] = 'h';

	//printf("s1: %s\n", s1);
	//printf("s2: %s\n", s2);

	char s1[] = { 'H', 'E', 'L', 'L', 'O', '\0' };
	char s2[] = "HELLO";	// �Ƽ�1
	char s3[10] = "HELLO";	// �Ƽ�2
	char s4[6] = "HELLO";
	char s5[5] = "HELLO";	// ����ʾ�ַ���!

	printf("s5: %s\n", s5);

	// 2. �ַ��������Ĳ���
	// a. �ַ�����֧�ֵĲ������ַ�����֧�֡� ȡ�±�[]
	// b. <string.h> �����˺ܶ�⺯�� -- ��չ�ַ������͵Ĳ���


	return 0;
}