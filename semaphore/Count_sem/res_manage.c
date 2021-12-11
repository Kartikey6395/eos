//counting semaphore
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>


struct Buff
{
    int arr[2];
}resource[3];
int ptr;
int get;
int i =1,j=0,val;
sem_t sem1;
struct Buff *buffer;

//buffer=resource;
void *thread_1(void *arg)
{
    
  
    struct Buff *buffer;
   // while(1)
    
        printf("thread number--> 1 \n");
        ptr = getbuff();
     
       //printf("%d \t %d",buffer->arr[0],buffer->arr[1]);
        printf("arr = %d\n ",buffer[ptr].arr);
        //printf("buffer = %d\n ",(*arr));
        
        /*for(j=0;j<2;j++)*/
        
           // printf("arr[] = %d %d ",(buffer)->arr[0],(buffer)->arr[1]);
        

    
}

void *thread_2(void *arg)
{
   // while(1)
   struct Buff *buffer;
    printf("thread number--> 2 \n");
buffer = getbuff();
//printf("%ld \t %ld",buffer->arr[0],buffer->arr[1]);
 printf("buff->arr = %d\n ",buffer->arr);
        printf("arr = %d\n ",buffer[ptr].arr);
        /*for(j=0;j<2;j++)
        {
            printf("arr[j] = %d ",(buffer)->arr[j]);
        }*/
}

void *thread_3(void *arg)
{
    //while(1)
   struct Buff *buffer;
    printf("thread number--> 3 \n");
buffer = getbuff();
//printf("%d \t %d",buffer->arr[0],buffer->arr[1]);
 printf("buff->arr = %d\n ",buffer->arr);
         printf("arr = %d\n ",buffer[ptr].arr);
        /*for(j=0;j<2;j++)
        {
            printf("arr[j] = %d ",(buffer)->(arr));
        }*/
}

void *thread_4(void *arg)
{
    //while(1)
   struct Buff *buffer;
    printf("thread number--> 4 \n");
buffer=getbuff();

 printf("buff->arr = %d\n ",buffer->arr);
        printf("arr = %d\n ",buffer[ptr].arr);
       /* for(j=0;j<2;j++)
        {
            printf("arr[j] = %d ",(buffer)->arr[j]);
        }*/
}

void *thread_5(void *arg)
{
   // while(1)
    struct Buff *buffer;
    printf("thread number--> 5\n");
buffer = getbuff();
//printf("%d \t %d",buffer->arr[0],buffer->arr[1]);
 printf("buff->arr = %d\n ",buffer->arr);
        printf("arr = %d\n ",buffer[ptr].arr);
        /*for(j=0;j<2;j++)
        {
            printf("arr[j] = %d ",(buffer)->arr[j]);
        }*/
}

void *thread_6(void *arg)
{
    //while(1)
    struct Buff *buffer;
    printf("thread number--> 6 \n");
buffer = getbuff();
//printf("%d \t %d",buffer->arr[0],buffer->arr[1]);
 printf("buff->arr = %d\n ",buffer->arr);
         printf("arr = %d\n ",buffer[ptr].arr);
        /*for(j=0;j<2;j++)
        {
            printf("arr[j] = %d ",(buffer)->arr[j]);
        }*/
 
}

void *thread_7(void *arg)
{
    //while(1)
    struct Buff *buffer;
    printf("thread number--> 7 \n");
buffer = getbuff();
//printf("%d \t %d",buffer->arr[0],buffer->arr[1]);
 printf("buff->arr = %d\n ",buffer->arr);
        printf("arr = %d\n ",buffer[ptr].arr);
        /*for(j=0;j<2;j++)
        {
            printf("arr[j] = %d ",(buffer)->arr[j]);
        }*/
}
//int count_T = 1;
int main(int argc,char const *argv[])
{
    struct Buff *buffer;
    buffer=resource;
    int k;
    //struct Buff resource = {123,345};
    pthread_t thread_id_1;
    pthread_t thread_id_2;
    pthread_t thread_id_3;
    pthread_t thread_id_4;
    pthread_t thread_id_5;
    pthread_t thread_id_6;
    pthread_t thread_id_7;
   // char sp='\n';
    printf("input arr elements\n");
    for(k=0;k<4;k++)
    {
        scanf("%d%d",&(buffer+k)->arr[0],&(buffer+k)->arr[1]);
    }
    
    sem_init(&sem1,0,4); 
    //while(count_T <= 10)
    
        
    pthread_create(&thread_id_1,NULL,thread_1,NULL);
    pthread_create(&thread_id_2,NULL,thread_2,NULL);
    pthread_create(&thread_id_3,NULL,thread_3,NULL);
    pthread_create(&thread_id_4,NULL,thread_4,NULL);
    pthread_create(&thread_id_5,NULL,thread_5,NULL);
    pthread_create(&thread_id_6,NULL,thread_6,NULL);
    pthread_create(&thread_id_7,NULL,thread_7,NULL);
    pthread_join(thread_id_1,NULL);
    pthread_join(thread_id_2,NULL);
    pthread_join(thread_id_3,NULL);
    pthread_join(thread_id_4,NULL);
    pthread_join(thread_id_5,NULL);
    pthread_join(thread_id_6,NULL);
    pthread_join(thread_id_7,NULL);

    sem_destroy(&sem1);


    
}

int getbuff()
{
    
    
    int mem;
    mem=i%4;
        if((sem_wait(&sem1))==0)
        {
      release_buff(); 
        
        return get;
        }//if(val==0)
       // {
        //return get;
       //     
       // }
     
   else
    get = mem;
    //printf("%lu",get);
        //sem_post(&sem1);
        //return rel;
    
    i++;
    return get;
}

void release_buff()
{   int get_res;
    get_res=i%4;
   // printf("%lu",get);
        get = get_res;
    i++;
    sem_post(&sem1);
    //return get;
    //return 0;
    //else
   // return 1;

}
