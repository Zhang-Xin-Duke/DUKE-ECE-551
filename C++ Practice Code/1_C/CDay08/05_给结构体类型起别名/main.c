#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

 // typedef ���� ����;
//typedef struct {
//	int number;		// ��Ա
//	char name[25];
//	char gender;
//	int chinese;
//	int math;
//	int english;
//} Student;

// �����ṹ�� (û�б�ǩ�Ľṹ������)
struct {
	int a, b, c;
} x,y,z; // x,y,z�ǽṹ�����

int x1, y1, z1;

// ǧ��Ҫ��ô����
// ��Ҫ��ָ�������������
typedef struct student{
	int number;		
	char name[25];
	char gender;
	int chinese;
	int math;
	int english;
} Student, *pStudent;

int main(void) {
	Student s1;
	pStudent p1;
	Student* p2;
	return 0;
}