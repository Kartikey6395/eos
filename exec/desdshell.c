//exec demo
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(int argc,char const *argv[])
{
    unsigned char cmd[10],buff[10];
    pid_t id;
    int ex,arr[20],fd[2];
    
    pipe(fd);
    //printf("before fork\n");
    id=fork();              //opaque return type pid_t
    

    
    if( id == 0)
    {
        close(fd[1]);
    //printf("Child Process-->before exec\n");                    //child

    read(fd[0],buff,sizeof(buff));

    execl(buff,buff,NULL);     //loading cmd prog onto child process
        if (ex == -1)
        {
            perror("Wrong command \n");              //checking for error
            printf("%d \n",errno);
            printf("desdshell $ ");
        
        }  
    printf("Child Process-->after exec\n");
    }

    else
    {
        //parent
        
        while(1)
        {
            printf("desdshell $ ");
            scanf("%s",cmd);
            //printf("after fork\n");

            write(fd[1],(char *)cmd,sizeof(cmd));
            close(fd[0]);
        }

     //printf("parent process--> \n");
    }
    

    printf("process ended\n");

}