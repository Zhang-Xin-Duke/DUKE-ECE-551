#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
// ��ָ�룺��ָ���κζ����ָ�롣һ����NULL(0)��ʾ��ָ��
//		  ���ܶԿ�ָ����н�����

// void*�� ͨ��ָ������ (��֪����������ʲô).
//        ���ԣ����Ժ��������͵�ָ���໥ת�� (��ʽת��)
//        ���ܶ�ͨ��ָ�����͵ı���������
int main(void) {

	// int* p = malloc(sizeof(int) * 1000);    /* malloc = memory + allocate */
	void* p = calloc(1000, sizeof(int));		   /* calloc = clear + allocate */

	// printf("%d\n", *p);
	return 0;
}