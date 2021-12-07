//pthreads
#include <stdio.h>
#include <pthread.h>

void *greet_thread(void*arg)
{
    printf("%s \n",arg);
}

int main(int argc,const char *argv[])
{
    pthread_t hello_id,Bye_id;
    printf("main thread:before creating hello thread \n");

    pthread_create(&hello_id,NULL, greet_thread,"hello thread");
    pthread_join(hello_id,NULL);

    pthread_create(&Bye_id,NULL, greet_thread,"Bye thread");
    pthread_join(Bye_id,NULL);

    printf("main thread:after creating Bye thread \n");
    return 0;
}