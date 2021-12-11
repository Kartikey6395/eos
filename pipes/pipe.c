// inter procces communication usin pipes:parent write -->child read
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char const *argv[])
{
    pid_t id;                   //has return type of pid from fork
    int fd[2];                      //file descrpter array
    unsigned char buff[30];

    pipe(fd);
        // returns two file descriptors-->fd[0]:read,fd[1]-->write
    id= fork();
    if(id == 0)             //child
    {
        close(fd[1]);
        printf("child reading process \n");
        read(fd[0],buff,25);
        printf("child read %s\n",buff );

    }
    else                            //parent
    {
        close(fd[0]);
        printf("parent writing process \n");
        write(fd[1],"Inter Processing Comm",22);
        printf("parent write done \n");
    }




}
