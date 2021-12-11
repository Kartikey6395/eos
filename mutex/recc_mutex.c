//pthreads :reccursive type attribute of mutex
#include <stdio.h>
#include <pthread.h>

int count=1;                //shared resource
pthread_mutex_t mutexCount;             //declaring mutex
pthread_mutexattr_t mutexCountAttr;         //declaring attributes of mutex

void square()
{
    printf("square Grab inside Inc \n");
    pthread_mutex_lock(&mutexCount);
    count = count * count;
    //printf("square-->  \n",count);
    pthread_mutex_unlock(&mutexCount);
    printf("square release inside Inc \n");
    
}

void *inc_thread(void*arg)
{
    while(1)
     {   //lock T1
        printf("Inc Grab \n");
         pthread_mutex_lock(&mutexCount);
         printf("critcal region : Inc \n");
         square();
         
         count++;
        printf("Increment %d \n",count);
        pthread_mutex_unlock(&mutexCount);
        printf("Inc release \n");
        //unlock T1
     }  
}

void *dec_thread(void*arg)
{
    while(1)
     {   //lock T2
        printf("Dec Grab \n");
         pthread_mutex_lock(&mutexCount);
         printf("critcal region : Dec \n");
         count--;
        printf("Decrement %d \n",count);
        pthread_mutex_unlock(&mutexCount);
        printf("Dec release \n");
            //unlock T2
     }
}


int main(int argc,const char *argv[])
{
    pthread_t inc_id,dec_id;
    printf("main thread:before creating  thread \n");

    pthread_mutexattr_init(&mutexCountAttr);                    //initialising attribute   
    pthread_mutexattr_settype(&mutexCountAttr,PTHREAD_MUTEX_RECURSIVE);         //setting type of attribute
    pthread_mutex_init(&mutexCount,&mutexCountAttr);

    pthread_create(&inc_id,NULL, inc_thread,NULL);
    

    pthread_create(&dec_id,NULL, dec_thread,NULL);
    pthread_join(dec_id,NULL);
    pthread_join(inc_id,NULL);
    pthread_mutex_destroy(&mutexCount);
    pthread_mutexattr_destroy(&mutexCountAttr);

    printf("main thread:after creating thread \n");
    return 0;
}