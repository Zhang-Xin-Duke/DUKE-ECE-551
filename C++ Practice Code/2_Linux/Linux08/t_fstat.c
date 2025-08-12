#include <func.h>

int main(int argc, char* argv[])
{
	// ./t_fstat file
	if (argc != 2) {
		error(1, 0, "Usage: %s file", argv[0]);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		error(1, errno, "open");
	}

	// 获取文件的元数据
	struct stat sb;
	if (fstat(fd, &sb) == -1) {
		error(1, errno, "fstat");
	}

	close(fd);

	// 打印文件的元数据
	printf("st_ino = %lld, st_mode = %o, st_nlinks = %lu, st_size = %ld, st_blocks = %ld\n", 
		   (long long)sb.st_ino,
		   sb.st_mode,
		   sb.st_nlink,
		   sb.st_size,
		   sb.st_blocks);
    return 0;
}

