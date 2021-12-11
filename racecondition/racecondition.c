//pthreads
#include <stdio.h>
#include <pthread.h>

int count=10;
void *inc_thread(void*arg)
{
    while(1)
     {   count++;
        printf("Increment %d \n",count);
     }  
}

void *dec_thread(void*arg)
{
    while(1)
     {   count--;
        printf("Decrement %d \n",count);
     }
}


int main(int argc,const char *argv[])
{
    pthread_t inc_id,dec_id;
    printf("main thread:before creating  thread \n");

    pthread_create(&inc_id,NULL, inc_thread,NULL);
    

    pthread_create(&dec_id,NULL, dec_thread,NULL);
    pthread_join(dec_id,NULL);
    pthread_join(inc_id,NULL);

    //printf("main thread:after creating Bye thread \n");
    return 0;
}