#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// ����ͷ�ļ���·����ϵͳ��includeĿ¼������
#include "Vector.h" // ����ͷ�ļ���·������ǰĿ¼ --> ϵͳ��includeĿ¼������

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

/*
��Ԫ����
*/
int main(void) {
	Vector* v = vector_create();	// �����յĶ�̬����

	for (int i = 1; i <= 100; i++) {
		push_back(v, i * 10);
	}

	for (int i = 0; i < v->size; i++) {
		printf("%d ", v->elements[i]);
	}
	printf("\n");

	vector_destroy(v);
	return 0;
}