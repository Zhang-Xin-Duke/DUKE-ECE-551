#include <func.h>

// #define MAXSIZE 10 

int main(int argc, char* argv[])
{
	// char buf[MAXSIZE];
	char* cwd = getcwd(NULL, 0); // cwd指向堆空间
	if (cwd == NULL) {
		error(1, errno, "getcwd");
	}

	puts(cwd);
	free(cwd);  // 不要忘记free!
    return 0;
}

