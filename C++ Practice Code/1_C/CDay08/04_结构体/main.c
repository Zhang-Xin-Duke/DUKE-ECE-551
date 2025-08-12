#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
/*
面向对象
	类：属性、行为 (方法)
面向过程 (C语言)：
	结构体：数据
	用户自定义类型

学生：
	属性：学号、姓名、性别、语文、数学、英语
	行为 (函数)
*/

// 定义类型
struct student {
	int number;		// 成员
	char name[25];
	char gender;
	int chinese;
	int math;
	int english;
};


// 输出
void print_stu_info(const struct student* s) {
	//printf("%d %s %c %d %d %d\n",
	//	(*s).number,
	//	(*s).name,
	//	(*s).gender,
	//	(*s).chinese,
	//	(*s).math,
	//	(*s).english);

	// ->: 左边是指向结构体的指针，右边结构体成员
	// s->name  等价于 (*s).name
	printf("%d %s %c %d %d %d\n",
		s->number,
		s->name,
		s->gender,
		s->chinese,
		s->math,
		s->english);
}

// 输入
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
	// 定义结构体变量
	// 类型：struct student, 变量名: s1
	struct student s1 = {1, "liuyifei", 'F', 100, 100, 100};	
	struct student s2 = {2, "peanut", 'M'};	

	// 结构体变量的操作
	// 1. 获取成员  
	// printf("%s: %d %d %d\n", s1.name, s1.chinese, s1.math, s1.english);
	// 2. 赋值 (复制)
	// 好处：复制结构体
	// 坏处：结构体作为参数或者返回值时，会导致整个结构体的复制！
	// 往往传递是指向结构体的指针！
	// s2 = s1;

	//print_stu_info(&s1);
	//print_stu_info(&s2);

	struct student s3;
	input_stu_data(&s3);

	return 0;
}