#include "head.h"


// 启动子线程
int init_thread(status_t *status){


    for(int i=0; i<status->num ; i++){
        pthread_create(&status->thread_ids[i], 
                       NULL,
                       thread_main,
                       status);
    }

    return 0;
}


