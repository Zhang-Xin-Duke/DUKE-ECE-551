#include <func.h>

#define MAXLEN 1024

int directories = 0, files = 0;

void dfs_print(const char* path, int width);
int main(int argc, char* argv[])
{
	// ./t_tree dir
	// 1. 参数校验
	if (argc != 2) {
		error(1, 0, "Usage: %s dir", argv[0]);
	}
	// 2. 打印根结点
	puts(argv[1]);
	// 3. 递归打印每一个目录项
	dfs_print(argv[1], 4);
	// 4. 打印统计信息
	printf("\n%d directories, %d files\n", directories, files);
    return 0;
}

void dfs_print(const char* path, int width) {
	// 递归地打印path里面的每一个目录项
	DIR* stream = opendir(path);
	if (!stream) {
		error(1, errno, "opendir");
	}

	// 惯用法
	errno = 0;
	struct dirent* curr;
	while ((curr = readdir(stream)) != NULL) {
		// 忽略隐藏文件
		const char* filename = curr->d_name;
		if (filename[0] == '.') {
			continue;
		}
		// 输出该目录项
		for (int i = 0; i < width; i++) {
			putchar(' ');
		}
		puts(filename);
		
		if (curr->d_type == DT_DIR) {
			directories++;
			// 递归处理
			// 拼接路径
			char subpath[MAXLEN];
			sprintf(subpath, "%s/%s", path, filename);
			dfs_print(subpath, width + 4);

		} else if (curr->d_type == DT_REG) {
			files++;
		}
	}

	if (errno) {
		error(1, errno, "readdir");
	}
	// 关闭目录流
	closedir(stream);
}
