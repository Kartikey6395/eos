//pthreads -->mutex :avoiding racecondition
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int count=10;           //shared resource
sem_t semCount;

void *inc_thread(void*arg)
{
    while(1)//write
     {   //lock T1
         sem_wait(&semCount);
         count++;
        printf("Increment %d \n",count);
        sem_post(&semCount);
        //unlock T1
     }  
}

void *dec_thread(void*arg)
{
    while(1)//read
     {   //lock T2
         sem_wait(&semCount);
         count--;
        printf("Decrement %d \n",count);
        sem_post(&semCount);
            //unlock T2
     }
}


int main(int argc,const char *argv[])
{
    pthread_t inc_id,dec_id;
    printf("main thread:before creating  thread \n");
    sem_init(&semCount,0,1);            //semaphore init (opaque_data_type,0-->thread,sem=1)

    pthread_create(&inc_id,NULL, inc_thread,NULL);
    

    pthread_create(&dec_id,NULL, dec_thread,NULL);
    pthread_join(dec_id,NULL);
    pthread_join(inc_id,NULL);
    sem_destroy(&semCount);

    printf("main thread:after creating Bye thread \n");
    return 0;
}