#include <func.h>

#define MAXLINE 1024

int main(int argc, char* argv[])
{
	// 1. 先pipe
	int fields[2];
	if (pipe(fields) == -1) {
		error(1, errno, "pipe");
	}
	// 2. 再fork
	pid_t pid = fork();
	switch (pid) {
	case -1:
		error(1, errno, "fork");
	case 0:
		// 4. 子进程关闭管道的另一端
		close(fields[1]);
		char message[MAXLINE];
		read(fields[0], message, MAXLINE); // 如果管道没有数据，一直阻塞
		printf("child: %s", message);
		break;
	default:
		// 3. 父进程关闭管道的一端
		close(fields[0]);
		sleep(5);
		write(fields[1], "Hello From Parent\n", 18 + 1); // +1 for '\0'
	}
    return 0;
}

