#include <func.h>

int simple_system(const char* command) {
	pid_t childPid = fork();
	int status;

	switch (childPid) {
	case -1: /* Error */
		return -1;
	case 0:	/* Child */
		execl("/bin/sh", "sh", "-c", command, NULL);
		_exit(127);		/* Failed exec */

	default: /* Parent */
		if (waitpid(childPid, &status, 0) == -1) {
			return -1;
		} else {
			return status;
		}
	}
}

int main(int argc, char* argv[])
{
    return 0;
}

