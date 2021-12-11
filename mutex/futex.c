//pthreads -->mutex :avoiding racecondition
#include <stdio.h>
#include <pthread.h>

int count=10;               //shared resource
pthread_mutex_t mutexCount;

void *inc_thread(void*arg)
{
    while(1)
     {   //lock T1
         pthread_mutex_lock(&mutexCount);
         count++;
        printf("Increment %d \n",count);
        pthread_mutex_unlock(&mutexCount);
        //unlock T1
     }  
}

void *dec_thread(void*arg)
{
    while(1)
     {   //lock T2
         pthread_mutex_lock(&mutexCount);
         count--;
        printf("Decrement %d \n",count);
        pthread_mutex_unlock(&mutexCount);
            //unlock T2
     }
}


int main(int argc,const char *argv[])
{
    pthread_t inc_id,dec_id;
    printf("main thread:before creating  thread \n");
    pthread_mutex_init(&mutexCount,NULL);

    pthread_create(&inc_id,NULL, inc_thread,NULL);
    

    pthread_create(&dec_id,NULL, dec_thread,NULL);
    pthread_join(dec_id,NULL);
    pthread_join(inc_id,NULL);
    pthread_mutex_destroy(&mutexCount);

    //printf("main thread:after creating Bye thread \n");
    return 0;
}