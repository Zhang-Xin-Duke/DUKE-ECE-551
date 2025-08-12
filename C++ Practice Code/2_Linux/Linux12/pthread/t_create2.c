#include <func.h>

void print_ids(const char* prefix) {
	printf("%s: pid = %d, ppid = %d, tid=0x%lx\n",
		   prefix,
		   getpid(),
		   getppid(),
		   pthread_self());
}

void* start_routine(void* args) {
	print_ids("new thread");
	printf("new thread: received %d\n", (int)args);
	return NULL;
}

int main(int argc, char* argv[])
{
	print_ids("main thread");
	// 创建新线程
	pthread_t tid; // 传出参数，用来接收新线程的ID
	int err = pthread_create(&tid, NULL, start_routine, (void*)9527);
	if (err) {
		error(1, err, "pthread_create");	// pthread: 返回错误码，不会设置errno
	}

	printf("main thread: create a thread 0x%lx\n", tid);

	sleep(2);
    return 0;   // exit(0): exit会导致进程退出，所有线程都会终止！
}

