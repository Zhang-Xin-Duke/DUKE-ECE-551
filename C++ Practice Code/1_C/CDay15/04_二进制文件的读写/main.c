#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 4096  
/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(int argc, char* argv[]) {
	// argv[0]: 可执行程序的路径
	// cp src dst

	// 参数校验
	if (argc != 3) {
		fprintf(stderr, "Usage: %s src dst\n", argv[0]);
		exit(1);
	}

	// 1. 打开文件
	FILE* src = fopen(argv[1], "rb");
	if (!src) {
		fprintf(stderr, "Open %s failed\n", argv[1]);
		exit(1);
	}

	FILE* dst = fopen(argv[2], "wb");
	if (!dst) {
		fprintf(stderr, "Open %s failed\n", argv[2]);
		fclose(src);
		exit(1);
	}

	// 2. 一块一块地读写 (fread, fwrite)
	// 惯用法
	char buffer[MAXSIZE];
	int n;   // 
	while ((n = fread(buffer, 1, MAXSIZE, src)) > 0) {
		fwrite(buffer, 1, n, dst);
	}
	return 0;
}