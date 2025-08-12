#include <func.h>

#define MAXLINE 1024

int main(int argc, char* argv[])
{
	int fields[2];
	// 创建管道
	if (pipe(fields) == -1) {
		// 失败
		error(1, errno, "pipe");
	}

	// fileds[0]: 读端，fileds[1]:写端
	write(fields[1], "Hello pipe\n", 11);

	char message[MAXLINE];
	read(fields[0], message, MAXLINE);
	printf("message: %s", message);
    return 0;
}

