// barrier between threads to execute at same time
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_barrier_t init_barrier;

void *e_prom_thread(void*arg)
{
    printf("e_prom_thread init start\n");
    sleep(3);
    pthread_barrier_wait(&init_barrier);
    printf("e_prom_thread init complete\n");
}

void *uart_thread(void*arg)
{
    printf("uart_thread init start\n");
    sleep(2);
    pthread_barrier_wait(&init_barrier);
    printf("uart_thread init complete\n");
}


void *ethern_thread(void*arg)
{
    printf("ethern_thread init start\n");
    sleep(6);
    pthread_barrier_wait(&init_barrier);
    printf("ethern_thread init complete\n");

}

void *i2c_thread(void*arg)
{
    printf("i2c_thread init start\n");
    sleep(2);
    pthread_barrier_wait(&init_barrier);
    printf("i2c_thread init complete\n");
}



int main(int argc,const char *argv[])
{
    pthread_t i2c,uart,ethern,e_prom;
    //printf("main thread:before creating hello thread \n");
    pthread_barrier_init(&init_barrier,NULL,4);

    pthread_create(&e_prom,NULL,e_prom_thread,NULL);
    pthread_create(&i2c,NULL,i2c_thread,NULL);
    pthread_create(&uart,NULL,uart_thread,NULL);
    pthread_create(&ethern,NULL,ethern_thread,NULL);
    pthread_join(i2c,NULL);
    pthread_join(uart,NULL);
    pthread_join(e_prom,NULL);
    pthread_join(ethern,NULL);

   // printf("main thread:after creating Bye thread \n");
    return 0;
}