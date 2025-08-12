#include <func.h>
#include <errno.h> 
#include <string.h>

int main(int argc, char* argv[])
{
	printf("errno = %d\n", errno);
	fprintf(stderr, "%s\n", strerror(errno));
	perror("aaa");

	FILE* fp = fopen("not_exist.txt", "r");
	if (!fp) {
		fprintf(stderr, "errno = %d\n", errno);
		fprintf(stderr, "%s\n", strerror(errno));
		perror("not_exist.txt");

		const char* prefix = "not_exist.txt";
		fprintf(stderr, "%s: %s\n", prefix, strerror(errno));

		error(1, errno, "not_exist.txt");
	}

	printf("Can you see me?\n");
	return 0;
}

