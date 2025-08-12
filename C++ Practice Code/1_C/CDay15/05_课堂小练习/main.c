#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
 *                          COMMENT                                   *
 **********************************************************************/
char* readFile(const char* path) {
	// 1. 打开文件流
	FILE* fp = fopen(path, "rb");
	if (!fp) {
		fprintf(stderr, "Open %s failed\n", path);
		exit(1);
	}

	// 2. 确定文件的大小
	fseek(fp, 0, SEEK_END);  // 将文件位置移动到文件的末尾
	long fsize = ftell(fp);  // 获取文件当前的位置

	// 动态申请数组
	rewind(fp);			// 回到文件的开头
	char* content = malloc(fsize + 1);	// +1 for '\0'
	int n = fread(content, 1, fsize, fp);
	content[n] = '\0';

	return content;
}

int main(int argc, char* argv[]) {
	// 参数校验
	if (argc != 2) {
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(1);
	}

	char* content = readFile(argv[1]);

	// 用完之后
	free(content);

	return 0;
}