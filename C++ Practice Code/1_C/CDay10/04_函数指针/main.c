#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
/*
定义函数指针变量：void (*func) (int, int);
函数地址：&foo, foo
通过函数指针调用函数：(*func)(实参列表), func(实参列表)
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
	
	// 总分越高，应该排在前面，逻辑上越小。
	if (total1 != total2) {
		// 逆向排序，调用qsort时，要交换顺序
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