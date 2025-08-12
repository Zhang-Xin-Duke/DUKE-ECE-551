#include <func.h>

int main(int argc, char* argv[])
{
	printf("Hello \n"); // 注意：没有换行

	pid_t pid = fork();		// 创建子进程
	switch (pid) {
	case -1:
		error(1, errno, "fork");
	case 0:
		// child
		printf("child: I am a baby\n");
		break;
	default:
		printf("parent: Who is your daddy?\n");
		// parent
		break;
	}
    return 0;
}

