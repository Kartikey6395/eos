//pthreads -->mutex :avoiding racecondition
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int count=10;           //shared resource
sem_t sem1;
sem_t sem2;
int a,b,result;

void *input_thread(void*arg)
{
    while(1)
     {   //sem1=1
         sem_post(&sem1);       //sem1=0
         printf("nums a & b \n");
         scanf("%d",&a);
         scanf("%d",&b);
        
        sem_post(&sem2);        //sem2=0
        //sem2=1
     }  
}

void *result_thread(void*arg)
{
    while(1)
     {   //sem2=1
         sem_wait(&sem2);           //sem2=0
         result= a + b;
        printf("result %d \n",result);
        sem_wait(&sem1);            //sem1=0
            //sem1=1
     }
}


int main(int argc,const char *argv[])
{
    pthread_t input_id,result_id;
    printf("main thread:before creating  thread \n");
    sem_init(&sem1,0,1);            //semaphore init (opaque_data_type,0-->thread,sem=1)
    

    pthread_create(&input_id,NULL, input_thread,NULL);
    
sem_init(&sem2,0,1);
    pthread_create(&result_id,NULL, result_thread,NULL);
    pthread_join(result_id,NULL);
    pthread_join(input_id,NULL);
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    printf("main thread:after creating Bye thread \n");
    return 0;
}