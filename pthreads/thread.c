//pthreads
#include <stdio.h>
#include <pthread.h>

void *hello_thread(void*arg)
{
    printf("hello thread\n");
}
void *Bye_thread(void*arg)
{
    printf("Bye thread\n");
}

int main(int argc,const char *argv[])
{
    pthread_t hello_id,Bye_id;
    printf("main thread:before creating hello thread \n");

    pthread_create(&hello_id,NULL, hello_thread,NULL);
    pthread_join(hello_id,NULL);

    pthread_create(&Bye_id,NULL, Bye_thread,NULL);
    pthread_join(Bye_id,NULL);

    printf("main thread:after creating Bye thread \n");
    return 0;
}