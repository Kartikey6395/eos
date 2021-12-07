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
    //printf("Child Process-->before exec\n");                    //child

    read(fd[0],buff,sizeof(buff));

    execl(buff,buff,NULL);     //loading cmd prog onto child process
        if (ex == -1)
        {
            perror("error-->Source not present \n");              //checking for error
            printf("%d",errno);
        
        }  
    printf("Child Process-->after exec\n");
    }

    else
    {
        //parent
    printf("desdshell $ ");
    scanf("%s",cmd);
    printf("after fork\n");

    write(fd[1],(char *)cmd,sizeof(cmd));

     //printf("parent process--> \n");
    }

    printf("process ended\n");

}