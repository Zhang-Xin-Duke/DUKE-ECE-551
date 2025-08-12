#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

 // typedef 类型 别名;
//typedef struct {
//	int number;		// 成员
//	char name[25];
//	char gender;
//	int chinese;
//	int math;
//	int english;
//} Student;

// 匿名结构体 (没有标签的结构体类型)
struct {
	int a, b, c;
} x,y,z; // x,y,z是结构体变量

int x1, y1, z1;

// 千万不要这么做！
// 不要给指针类型起别名！
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