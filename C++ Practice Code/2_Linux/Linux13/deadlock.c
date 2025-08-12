#include <func.h>

typedef struct {
	int id;
	int balance;
	// 注意点2：选择合适粒度的锁
	pthread_mutex_t mutex;
} Account;

Account acct1 = {1, 100, PTHREAD_MUTEX_INITIALIZER};
Account acct2 = {2, 1000, PTHREAD_MUTEX_INITIALIZER};

pthread_mutex_t protection = PTHREAD_MUTEX_INITIALIZER;

int transfer(Account* a, Account* b, int money) {
	// 加保护锁
	/* pthread_mutex_lock(&protection); */
	/* // 上锁 */
	/* pthread_mutex_lock(&a->mutex); */
	/* sleep(1);  // 放大了线程切换的概率 */
	/* pthread_mutex_lock(&b->mutex); */

	/* // 释放保护锁 */
	/* pthread_mutex_unlock(&protection); */
	
	// 2. 破坏不可抢占
/* start: */
/* 	pthread_mutex_lock(&a->mutex); */
/* 	sleep(1); */
/* 	int err = pthread_mutex_trylock(&b->mutex); */
/* 	if (err) { */
/* 		pthread_mutex_unlock(&a->mutex); // 主动释放 */
/* 		sleep(1); */
/* 		goto start; */
	// }
	
	// 3. 破坏循环等待
	if (a->id < b->id) {
		pthread_mutex_lock(&a->mutex);
		sleep(1);
		pthread_mutex_lock(&b->mutex);
	} else {
		pthread_mutex_lock(&b->mutex);
		sleep(1);
		pthread_mutex_lock(&a->mutex);
	}

	int ret;
	if (a->balance < money) {
		b->balance += a->balance;
		ret = a->balance;
		a->balance = 0;
		goto end;
	} 
	
	a->balance -= money;
	b->balance += money;
	ret = money;

end:
	pthread_mutex_unlock(&a->mutex);
	pthread_mutex_unlock(&b->mutex);
	return ret;
}

void* start_routine1(void* arg) {
	int money = (int)arg;
	int n = transfer(&acct1, &acct2, money);
	if (n > 0) {
		printf("0x%lx: acct1 transfer %d money to acct2\n", 
			   pthread_self(), n);
	}
	return NULL;
}

void* start_routine2(void* arg) {
	int money = (int)arg;
	int n = transfer(&acct2, &acct1, money);
	if (n > 0) {
		printf("0x%lx: acct2 transfer %d money to acct1\n", 
			   pthread_self(), n);
	}
	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, start_routine1, (void*)100);
	pthread_create(&tid2, NULL, start_routine2, (void*)500);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
    return 0;
}

