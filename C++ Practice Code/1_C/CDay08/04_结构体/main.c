#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
/*
�������
	�ࣺ���ԡ���Ϊ (����)
������� (C����)��
	�ṹ�壺����
	�û��Զ�������

ѧ����
	���ԣ�ѧ�š��������Ա����ġ���ѧ��Ӣ��
	��Ϊ (����)
*/

// ��������
struct student {
	int number;		// ��Ա
	char name[25];
	char gender;
	int chinese;
	int math;
	int english;
};


// ���
void print_stu_info(const struct student* s) {
	//printf("%d %s %c %d %d %d\n",
	//	(*s).number,
	//	(*s).name,
	//	(*s).gender,
	//	(*s).chinese,
	//	(*s).math,
	//	(*s).english);

	// ->: �����ָ��ṹ���ָ�룬�ұ߽ṹ���Ա
	// s->name  �ȼ��� (*s).name
	printf("%d %s %c %d %d %d\n",
		s->number,
		s->name,
		s->gender,
		s->chinese,
		s->math,
		s->english);
}

// ����
void input_stu_data(struct student* s) {
	scanf("%d%s %c%d%d%d",
		&s->number,
		s->name,
		&s->gender,
		&s->chinese,
		&s->math,
		&s->english);
}


int main(void) {
	// ����ṹ�����
	// ���ͣ�struct student, ������: s1
	struct student s1 = {1, "liuyifei", 'F', 100, 100, 100};	
	struct student s2 = {2, "peanut", 'M'};	

	// �ṹ������Ĳ���
	// 1. ��ȡ��Ա  
	// printf("%s: %d %d %d\n", s1.name, s1.chinese, s1.math, s1.english);
	// 2. ��ֵ (����)
	// �ô������ƽṹ��
	// �������ṹ����Ϊ�������߷���ֵʱ���ᵼ�������ṹ��ĸ��ƣ�
	// ����������ָ��ṹ���ָ�룡
	// s2 = s1;

	//print_stu_info(&s1);
	//print_stu_info(&s2);

	struct student s3;
	input_stu_data(&s3);

	return 0;
}