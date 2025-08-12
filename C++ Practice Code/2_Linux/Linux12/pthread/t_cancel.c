#include <func.h>

void* start_routine(void*) {
	// ENABLE, DEFFERRED
	int oldstate;
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &oldstate);

	/* int oldtype; */
	/* pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, &oldtype); */


	for(int i = 0; i < 10; i++) {
		sleep(1);
	}

	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);

	for(;;) {
		sleep(1);
	}
	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t tid;
	int err = pthread_create(&tid, NULL, start_routine, NULL);
	if (err) {
		fprintf(stderr, "pthread_create failed");
		pthread_exit(NULL);
	}

	sleep(3);

	err = pthread_cancel(tid);	// 发送取消请求
	if (err) {
		fprintf(stderr, "pthread_cancel failed");
		pthread_exit(NULL);
	}

	void* retval;
	pthread_join(tid, &retval);
	if (retval == PTHREAD_CANCELED) {
		printf("0x%lx canceled\n", tid); // 唯一的方式：判断目标线程是否响应了取消请求
	}
    return 0;
}

