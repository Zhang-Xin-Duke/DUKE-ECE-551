#include <func.h>

int main(int argc, char* argv[])
{
	int fd = open("a.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1) {
		error(1, errno, "open");
	}
	printf("current file offset: %ld\n", lseek(fd, 0, SEEK_CUR));
	
	int newfd;

	pid_t pid = fork();		// 创建子进程
	switch (pid) {
	case -1:
		error(1, errno, "fork");
	case 0:
		// child
		write(fd, "Hello world!", 12);

		// 验证：父子进程有自己的文件描述符列表
		close(STDERR_FILENO);
		newfd = dup(fd);
		printf("newfd = %d\n", newfd);	// newfd = 2
		close(STDERR_FILENO);
		break;
	default:
		// parent
		sleep(3);
		printf("current file offset: %ld\n", lseek(fd, 0, SEEK_CUR));

		newfd = dup(fd);
		printf("newfd = %d\n", newfd); // newfd = 4
		break;
	}
    return 0;
}

