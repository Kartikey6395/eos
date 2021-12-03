//sending two integers from parent to child and returning back their sum 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char const *argv[])
{
    pid_t id;                   //return of pid from fork
    int arr[2],buff[2],sum=0,result,i;
    int fd_1[2];                    //fd for pipe1
    int fd_2[2];                      //fd for pipe2
    
     printf("input two integers \n");
        //scanf("%d %d",arr[0],arr[1]);
        for(i=0;i<2;i++)
        {
          scanf("%d",&arr[i]);
        }   
 
    
    pipe(fd_1);
    pipe(fd_2);

        // returns two file descriptors each-->fd_x[0]:read,fd_x[1]-->write
    

    
    id= fork();
    if(id == 0)             //child
    {
        close(fd_1[1]);
        close(fd_2[0]);
       
        printf("child reading process \n");
        read(fd_1[0],buff,8);
        
        for(i=0;i<2;i++)
        {
            sum=sum+buff[i];
        }
       
       write(fd_2[1],&sum,4);

        printf("child read %d\n",sum);
      

    }
    else                            //parent
    {
        int i=0;   
        close(fd_1[0]);
        close(fd_2[1]);
        
        
        printf("parent writing process \n");
        write(fd_1[1],arr,8);
        
        read(fd_2[0],&result,4);
        printf("parent write done %d\n",result);
         
   
    }

    

}


