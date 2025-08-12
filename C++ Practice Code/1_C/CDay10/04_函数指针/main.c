#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
/*
���庯��ָ�������void (*func) (int, int);
������ַ��&foo, foo
ͨ������ָ����ú�����(*func)(ʵ���б�), func(ʵ���б�)
*/

//void foo(int a, int b) {
//	printf("Foo: %d\n", a + b);
//}
//
//void bar(int a, int b) {
//	printf("Bar: %d\n", a * b);
//}

typedef struct {
	int  id;
	char name[25];
	int  chinese;
	int  math;
	int  english;
} Student;

int compare(const void* p1, const void* p2) {
	const Student* s1 = p1;
	const Student* s2 = p2;

	int total1 = s1->chinese + s1->math + s1->english;
	int total2 = s2->chinese + s2->math + s2->english;
	
	// �ܷ�Խ�ߣ�Ӧ������ǰ�棬�߼���ԽС��
	if (total1 != total2) {
		// �������򣬵���qsortʱ��Ҫ����˳��
		return total2 - total1;
	}
	if (s1->chinese != s2->chinese) {
		return s2->chinese - s1->chinese;
	}
	if (s1->math != s2->math) {
		return s2->math - s1->math;
	}
	if (s1->english != s2->english) {
		return s2->english - s1->english;
	}

	return strcmp(s1->name, s2->name);
}

int main(void) {
	//void (*func) (int, int);

	//func = foo;
	//func(3, 4);

	//printf("--------------\n");

	//func = &bar;
	//(*func)(3, 4);

	Student students[5];
	for (int i = 0; i < 5; i++) {
		scanf("%d%s%d%d%d",
			&students[i].id,
			students[i].name,
			&students[i].chinese,
			&students[i].math,
			&students[i].english);
	}

	qsort(students, 5, sizeof(Student), compare);

	return 0;
}