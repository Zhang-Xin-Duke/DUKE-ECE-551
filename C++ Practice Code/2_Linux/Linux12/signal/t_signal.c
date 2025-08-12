#include <func.h>

void handler(int signo) {
	switch (signo) {
	case SIGINT: 
		printf("Caught SIGINT\n");
		break;
	case SIGTSTP:
		printf("Caught SIGTSTP\n");
		break;
	/* case SIGQUIT: */
	/* 	printf("Caught SIGQUIT\n"); */
	/* 	break; */
	default:
		printf("Caught UNKNOWN\n");
		break;
	}
}

int main(int argc, char* argv[])
{
	// 注册信号处理函数
	sighandler_t oldhandler = signal(SIGINT, handler);
	if (oldhandler == SIG_ERR) {
		error(1, errno, "signal SIGINT");
	}

	oldhandler = signal(SIGTSTP, handler);
	if (oldhandler == SIG_ERR) {
		error(1, errno, "signal SIGTSTP");
	}

	/* oldhandler = signal(SIGSTOP, handler); */
	/* if (oldhandler == SIG_ERR) { */
	/* 	error(1, errno, "signal SIGSTOP"); */
	/* } */

	for(;;);

    return 0;
}

