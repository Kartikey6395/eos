//exec demo
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(int argc,char const *argv[])
{

    pid_t id;
    int ex;
    printf("before fork\n");
    
    id=fork();              //opaque return type pid_t
    printf("after fork\n");
    
    if( id == 0)
    {
    printf("Child Process-->before exec\n");                    //child
    execl("/home/ktubuntu/EOS/work/piddemo/pidbin","pidbin",NULL);     //loading getpid prog onto child process
    if (ex == -1)
    {
        perror("error-->Source not present \n");              //checking for error
        printf("%d",errno);
    
    }  

    printf("Child Process-->after exec\n");
    }
    else
    printf("parent process--> \n");          //parent

    printf("process ended\n");

}