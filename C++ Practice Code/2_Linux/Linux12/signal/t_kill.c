#include <func.h>

int main(int argc, char* argv[])
{
	// ./t_kill signo pid
	if (argc != 3) {
		error(1, 0, "Usage: %s signo pid", argv[0]);
	}
	// 参数转换
	int signo;
	pid_t pid;
	sscanf(argv[1], "%d", &signo);
	sscanf(argv[2], "%d", &pid);

	if (kill(pid, signo) == -1) {
		error(1, errno, "kill");
	}
    return 0;
}

