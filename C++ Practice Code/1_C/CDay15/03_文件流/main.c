#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 128
/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

struct student {
	int number;
	char name[25];
	char gender;
	int chinese;
	int math;
	int english;
};

int main(void) {
	// 1. 打开文件流
	FILE* src = fopen("a.txt", "r");
	if (!src) {
		fprintf(stderr, "Open failed: a.txt\n");
		exit(1);
	}

	FILE* dst = fopen("b.txt", "w");
	if (!dst) {
		fprintf(stderr, "Open failed: b.txt\n");
		fclose(src);
		exit(1);
	}

	// 2. 读写文件流
	// a. 一个字符一个字符地读写 (fgetc, fputc)
	// rotate13 (加密算法：解密算法也是 rotate13)
	// abcdefghijklm   nopqrstuvwxyz

	// 惯用法！
	//int c;
	//while ((c = fgetc(src)) != EOF) {
	//	if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M')) {
	//		fputc(c + 13, dst);
	//	} else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z')) {
	//		fputc(c - 13, dst);
	//	} else {
	//		fputc(c, dst);
	//	}
	//} // 读到了EOF


	// b. 一行一行地读写 (fgets, fputs)
	//int number = 1;

	//char line[MAXLINE];
	//char message[MAXLINE];
	//while (fgets(line, MAXLINE, src) != NULL) {
	//	sprintf(message, "%d. %s", number, line);
	//	fputs(message, dst);
	//	number++;
	//} 

	// c. 格式化地读写 (fscanf, fprintf)
	//struct student s;
	//for (;;) {
	//	int n = fscanf(src, "%d%s %c%d%d%d",
	//		&s.number,
	//		s.name,
	//		&s.gender,
	//		&s.chinese,
	//		&s.math,
	//		&s.english);

	//	if (n != 6) break;

	//	s.chinese *= 0.8;
	//	s.math *= 0.85;
	//	s.english *= 0.9;

	//	fprintf(dst, "%d %s %c %d %d %d\n",
	//		s.number,
	//		s.name,
	//		s.gender,
	//		s.chinese,
	//		s.math,
	//		s.english);
	//}

	// (2) 二进制文件的读写



	// 3. 关闭文件流
	fclose(src);
	fclose(dst);

	return 0;
}