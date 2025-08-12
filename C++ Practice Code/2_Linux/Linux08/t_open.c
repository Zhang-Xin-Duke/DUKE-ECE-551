#include <func.h>

int main(int argc, char* argv[])
{
	/* int fd = open("a.txt", O_RDWR | O_CREAT | O_TRUNC, 0666); */
	int fd = open("a.txt", O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd == -1) {
		error(1, errno, "open");
	}

	printf("current offset: %ld\n", lseek(fd, 0, SEEK_CUR));
	write(fd, "kitty", 5);
	printf("current offset: %ld\n", lseek(fd, 0, SEEK_CUR));

	int fd2 = open("a.txt", O_RDONLY);
	printf("fd2 = %d\n", fd2);
	printf("fd2: offset = %ld\n", lseek(fd2, 0, SEEK_CUR));
    return 0;
}

