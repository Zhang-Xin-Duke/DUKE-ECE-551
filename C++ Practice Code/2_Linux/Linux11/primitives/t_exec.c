#include <func.h>

int main(int argc, char* argv[])
{
	printf("pid = %d, ppid = %d\n", getpid(), getppid());

	printf("Begin\n");
	
	/* const char* arguments[] = {"echoall", "aaa", "bbb", "ccc", NULL}; */
	char* const envp[] = {"USER=he", "KEY=value", NULL};
	// execve("echoall", arguments, envp);
	// execl("echoall", "./echoall", "aaa", "bbb", "cccc", NULL);	// l: list

	// execlp("echoall", "./echoall", "aaa", "bbb", "cccc", NULL);	// l: list
	execle("/usr/bin/echoall", "aaa", "bbb", NULL, envp);
	printf("Can you see me?\n");
	error(1, errno, "exeve");

    return 0;
}

