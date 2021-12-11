#include <stdio.h> 
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h> 
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <semaphore.h>

int *shm_ptr;           //return address of shared memory
sem_t sem_shm;

int num;
int main()
{
    int shm_fd;             //file descriptor -->int type

    sem_init(&sem_shm,1,1);

    shm_fd = shm_open("/desd_shm",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
    if(shm_fd == -1)
    {
        perror("error msg \n");
    }
    ftruncate(shm_fd,sizeof(int));

    shm_ptr = (int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);

    while(1)
    {
        sem_wait(&sem_shm);
        printf("input num\n");
        scanf("%d",&num);
        *shm_ptr = num;
        sem_post(&sem_shm);

    }
    shm_unlink("/desd_shm");
    sem_destroy(&sem_shm);
    

    return 0;
}