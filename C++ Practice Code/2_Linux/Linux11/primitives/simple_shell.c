#include <func.h>

#define MAXLINE 1024
#define MAXARGS 128

void print_wstatus(int status) {
	if (WIFEXITED(status)) {
		printf("Exit code: %d\n", WEXITSTATUS(status));
	} else if (WIFSIGNALED(status)) {
		printf("Terminate signal: %d ", WTERMSIG(status));
#ifdef WCOREDUMP
		if (WCOREDUMP(status)) {
			printf("(core dump)");
		}
#endif
		printf("\n");
	}
}

void parse_parameter(char* message, char* argv[]) {
	int i = 0;
	argv[i] = strtok(message, " \t\n");
	
	while (argv[i]) {
		i++;
		argv[i] = strtok(NULL, " \t\n");
	} // argv[i] == NULL
}

int main(int argc, char* argv[])
{
	char cmd[MAXLINE];
	char* parameters[MAXARGS];
	
	for(;;) {
		// 读取用户输入的命令
		printf("%s", "SimpleShell > ");
		fgets(cmd, MAXLINE, stdin);
		// 如果cmd为exit，终止进程
		if (strcmp(cmd, "exit\n") == 0) {
			exit(0);
		}
		// 创建子进程，让子进程执行命令
		pid_t pid = fork();

		switch (pid) {
		case -1:
			error(1, errno, "fork");
		case 0: // 子进程
			// 解析命令行参数
			parse_parameter(cmd, parameters);
			if (execvp(parameters[0], parameters) == -1) {
				error(1, errno, "exevp");
			}
			break;
		default:
			int status;
			if (waitpid(pid, &status, 0) == -1) {
				error(1, errno, "waitpid");
			}
			// 打印子进程的终止状态信息
			printf("%d terminated\n", pid);
			print_wstatus(status);
		}
	}
    return 0;
}

