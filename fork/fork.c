//fork operation
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char const *argv[])
{
    pid_t id;

    id=fork();              //opaque return type pid_t
    printf("ID-->%d\n",id);
    if( id == 0)
    {
    printf("Child Process-->%d\n",getpid());
    printf("Child Process-->%d\n",getppid());
    }
    else
    printf("parent process--> %d\n",getpid());

}