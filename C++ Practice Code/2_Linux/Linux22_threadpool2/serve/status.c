#include "head.h"


// 初始化共享的数据
int init_status(status_t * status, int num){

    status->num = num;
    status->thread_ids = (pthread_t *)malloc(num*sizeof(pthread_t));

    memset(&status->queue, 0, sizeof(queue_t));

    pthread_mutex_init(&status->lock, NULL);

    pthread_cond_init(&status->cond, NULL);

    return 0;
}


