#include <func.h>

typedef struct {
	int id;
	int balance;
	// 注意点2：选择合适粒度的锁
	pthread_mutex_t mutex;
} Account;

Account acct1 = {1, 100, PTHREAD_MUTEX_INITIALIZER};

// 锁的粒度太大！
// pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

int withdraw(Account* a, int money) {
	// 临界区之前上锁
	pthread_mutex_lock(&a->mutex);
	int ret;
	if (a->balance <= 0) {
		fprintf(stderr, "Error: not enough money!\n");
		// 注意点1：函数的每个出口都要释放锁
		ret = -1;
		goto end;
	}

	if (a->balance >= money) {
		sleep(1);  // 增大线程切换的概率
		a->balance -= money;
		ret = money;
		goto end;
	}
	ret = a->balance;
	a->balance = 0;
	// 临界区之后，释放锁
end:
	pthread_mutex_unlock(&a->mutex);
	return ret;
}

void* start_routine(void* arg) {
	int money = (int)arg;
	int n = withdraw(&acct1, money);
	if (n != -1) {
		printf("0x%lx: withdraw %d\n", pthread_self(), n);
	}
	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, start_routine, (void*)100);
	pthread_create(&tid2, NULL, start_routine, (void*)100);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
    return 0;
}

