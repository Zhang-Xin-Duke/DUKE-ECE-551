#include <func.h>

#define MAXLINE 1024

int main(int argc, char* argv[])
{
	char cmd[MAXLINE];
	fgets(cmd, MAXLINE, stdin);

	printf("%s", cmd);
	// 解析参数
	char* token = strtok(cmd, " \t\n");
	while (token) {
		puts(token);
		token = strtok(NULL, " \t\n");
	} // token == NULL
	
    return 0;
}

