#include "head.h"

void cleanup_unlock(void *p){
    pthread_mutex_t *lock = (pthread_mutex_t *)p;
    pthread_mutex_unlock(lock);
    printf("unlcok \n");
}
void * thread_main(void *p){

    status_t *status = (status_t *)p;

    while(1){
        // 1, 从队列中获取net_fd 
        int net_fd =0;
        pthread_mutex_lock(&status->lock);
        pthread_cleanup_push( cleanup_unlock, &status->lock  );

        while(status->queue.size <=0 ){
            pthread_cond_wait(&status->cond, &status->lock);
        }

        // 说明队列中, 有新的客户端的net_fd
        net_fd = status->queue.head->net_fd ;
        // 出队
        deQueue(&status->queue);

       // pthread_mutex_unlock(&status->lock);
       pthread_cleanup_pop(1);

        // 2, 客户端进行通信
        do_worker(net_fd);

        close(net_fd);
    }

    return NULL;
}

