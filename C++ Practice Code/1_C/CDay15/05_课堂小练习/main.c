#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
char* readFile(const char* path) {
	// 1. ���ļ���
	FILE* fp = fopen(path, "rb");
	if (!fp) {
		fprintf(stderr, "Open %s failed\n", path);
		exit(1);
	}

	// 2. ȷ���ļ��Ĵ�С
	fseek(fp, 0, SEEK_END);  // ���ļ�λ���ƶ����ļ���ĩβ
	long fsize = ftell(fp);  // ��ȡ�ļ���ǰ��λ��

	// ��̬��������
	rewind(fp);			// �ص��ļ��Ŀ�ͷ
	char* content = malloc(fsize + 1);	// +1 for '\0'
	int n = fread(content, 1, fsize, fp);
	content[n] = '\0';

	return content;
}

int main(int argc, char* argv[]) {
	// ����У��
	if (argc != 2) {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(1);
	}

	char* content = readFile(argv[1]);

	// ����֮��
	free(content);

	return 0;
}