#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 4096  
/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/

int main(int argc, char* argv[]) {
	// argv[0]: ��ִ�г����·��
	// cp src dst

	// ����У��
	if (argc != 3) {
		fprintf(stderr, "Usage: %s src dst\n", argv[0]);
		exit(1);
	}

	// 1. ���ļ�
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

	// 2. һ��һ��ض�д (fread, fwrite)
	// ���÷�
	char buffer[MAXSIZE];
	int n;   // 
	while ((n = fread(buffer, 1, MAXSIZE, src)) > 0) {
		fwrite(buffer, 1, n, dst);
	}
	return 0;
}