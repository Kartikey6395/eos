//prog to send file from p1 to p2 process
#include <stdio.h> 
#include<stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h> 
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <semaphore.h>
#include <string.h>

int main()
{
    sem_t s1;
    int fd,len=0,i=0,j;
    char *shm_ptr;
    char str[] = "exit";
    sem_init(&s1,1,1);
    unsigned char *buff;

    //fd=open("/home/ktubuntu/EOS/eos_lab_exam/dictionary.txt",O_RDWR ,S_IRUSR | S_IWUSR); 
    /*if (fd == -1)
    {
        perror("error-->Source not present \n");              //printf("%d",errno)-->errno 2
        printf("%d",errno);
    
    }  */
    int shm_fd;
    shm_fd = shm_open("/dictionary",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
    if(shm_fd == -1)
    {
        perror("error msg \n");
    }
    ftruncate(shm_fd,sizeof(int));
    shm_ptr = (char *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);
    //read(fd,buff,sizeof(buff));
    
    
    while(1)
    {
        sem_wait(&s1);
         //buff= shm_ptr;
         len = strlen(shm_ptr);
         printf("len = %d \n",len);
        
        
            printf("%s ",shm_ptr);
            //i++;
        
        /*printf("%c",*(shm_ptr));
      for(i=0;*(shm_ptr+i)!='m';i++)
        {
            len++;
           // printf("%c",*(shm_ptr+i));
        }
        printf("%s",(shm_ptr+1));
        printf("%c",*(shm_ptr+i));
        for(j=0;j>len;j++)
        {
            while(*(shm_ptr+j)!='\0')
            {
                printf("%c",*(shm_ptr+i));
                k++;
            }

        }*/
        
        sem_post(&s1);
        if(strcmp(shm_ptr,str)==0)
        exit(0);
    }  
    
   // printf("length of string-->%d",k);
         shm_unlink("/dictionary");
    sem_destroy(&s1);
    return 0;

    



}