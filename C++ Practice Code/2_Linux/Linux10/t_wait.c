#include <func.h>

// 解析子进程的终止状态
void print_wstatus(int wstatus) {
	if (WIFEXITED(wstatus)) {
		// 正常终止
		printf("exit status: %d\n", WEXITSTATUS(wstatus));
	} else if (WIFSIGNALED(wstatus)) {
		// 子进程异常终止
		printf("termination signal: %d", WTERMSIG(wstatus));
#ifdef WCOREDUMP 
		// 条件编译：编写可移植的程序
		if (WCOREDUMP(wstatus)) {
			printf("(core dump)");
		}
#endif
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	pid_t pid = fork();

	switch (pid) {
	case -1:
		error(1, errno, "fork");
	case 0:
		// 子进程
		printf("child: pid = %d\n", getpid());
		for(;;);
		// exit(18);
		// abort();
		break;
	default:
		// 父进程：等待子进程终止
		int wstatus;
		pid_t child = wait(&wstatus); // 一直阻塞，直到有一个子进程终止
		printf("child %d terminated\n", child);
		print_wstatus(wstatus);
	}
    return 0;
}

