#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SWAP(arr, i, j)	{	\
	Student t = arr[i];		\
	arr[i] = arr[j];		\
	arr[j] = t;				\
} 
/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
typedef struct stundent_s { 
	int number;
	char name[25];
	char gender;
	int chinese;
	int math;
	int english; 
} Student;


void print_stu_info(const Student* s) {
	printf("%d %s %c %d %d %d\n",
		s->number,
		s->name,
		s->gender,
		s->chinese,
		s->math,
		s->english);
}

void print_higest_score(Student students[], int n) {
	int idx1 = 0, idx2 = 0, idx3 = 0;

	for (int i = 1; i < n; i++) {
		if (students[i].chinese > students[idx1].chinese) {
			idx1 = i;
		}
		if (students[i].math > students[idx2].math) {
			idx2 = i;
		}
		if (students[i].english > students[idx3].english) {
			idx3 = i;
		}
	}

	print_stu_info(&students[idx1]);
	print_stu_info(&students[idx2]);
	print_stu_info(&students[idx3]);
}

int total_score(const Student* s) {
	return s->chinese + s->math + s->english;
}

void sort_students(Student students[], int n) {
	// —°‘Ò≈≈–Ú
	for (int i = 0; i < 4; i++) {
		// Œ¥≈≈–Ú‘™Àÿ [i, n£©
		int idx = i;
		for (int j = i + 1; j < n; j++) {
			if (total_score(&students[j]) > total_score(&students[idx])) {
				idx = j;
			}
		}
		SWAP(students, i, idx);
	}
}

int main(void) {
	Student students[5];
	for (int i = 0; i < 5; i++) {
		scanf("%d%s %c%d%d%d",
			&students[i].number,
			students[i].name,
			&students[i].gender,
			&students[i].chinese,
			&students[i].math,
			&students[i].english);
	}

	print_higest_score(students, 5);

	sort_students(students, 5);

	for (int i = 0; i < 5; i++) {
		print_stu_info(&students[i]);
	}

	return 0;
}