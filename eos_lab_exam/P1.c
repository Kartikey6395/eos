//prog to send file from p1 to p2 process
#include <stdio.h> 
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h> 
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <semaphore.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    sem_t s1;
    int fd,i=0,k;
    char *shm_ptr;
    sem_init(&s1,1,1);
    char *buff;
    size_t word =0,len;
    //char word[10];
    FILE *f1;
    char str[] ="exit"; 
   // char ch[]={'m'};
   buff = (char *)malloc (20);

    fd=open("/home/ktubuntu/EOS/eos_lab_exam/dictionary.txt",O_RDONLY ,S_IRUSR | S_IWUSR); 
    if (fd == -1)
    {
        perror("error-->Source not present \n");              //printf("%d",errno)-->errno 2
        printf("%d",errno);
    
    }  
    //f1="dictionary.txt";
    f1 = fopen("dictionary.txt","r");
    int shm_fd;
    shm_fd = shm_open("/dictionary",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
    if(shm_fd == -1)
    {
        perror("error msg \n");
    }
    ftruncate(shm_fd,sizeof(int));
    shm_ptr = (char *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);
   // printf("feof in ");
    
    while(getline(&buff,&word,f1)!=-1)
    { //fprintf(stdout,"%s",buff);
       /*printf("feof in ");
        do
        {int j=0;
            while(buff[i]!='\n')
            {
                word[j]=buff[i];
                ++j;
                ++i;
            }*/
            len = strlen(buff);
            
                if(buff[0]=='m')
                {
                    sem_wait(&s1);
                strcpy(shm_ptr,buff);
                printf("%s",shm_ptr);
                //shm_ptr += len;
                 sem_post(&s1);
                }
                // printf("%s",buff);
                memset(buff,' ',len);
           
        //

            
        //while(i<100);
    
       
    }
   

        //
        
        
        //for(i=0;i<(sizeof(buff));i++)
       /* while(buff[i]!='m')
           {
            
               i++;
               // printf("%c",buff[i]);
               
           }
               
               for(k=i;buff[k]!='\0';k=k+len)
               {
                   if(buff[k]=='m')
                    {strcpy(shm_ptr,&buff[k]);
                    len = strlen(shm_ptr);
                    shm_ptr = shm_ptr + len;}
               }
                  
                
           
          //  str=strcasecmp(buff,ch);
            //*shm_ptr=;
        
        sem_post(&s1);
    }*/
    //printf("%s ",shm_ptr);
        strcpy(shm_ptr,str);
         shm_unlink("/dictionary.txt");
    sem_destroy(&s1);
    close(fd);
    fclose(f1);
    
    return 0;



}