//open file and write-->user req to kernell via sys call
#include<stdio.h>
#include <sys/types.h>              //man open
#include <sys/stat.h>                   //man open
#include <fcntl.h>                          //man open
#include <unistd.h>                 //man 2 write
#include <stdlib.h>
#include <errno.h>                     //man errno

int main(int argc,char const *argv[])
{   
    char buf[]="System Call\n";
    
    int fd;                                   //rturn type open()-->int
    
    fd=open("DESD.txt",O_WRONLY|O_CREAT ,S_IRUSR | S_IWUSR);           //file descripter user read write only
    
    if (fd == -1)
    {
        perror("error--> \n");              //printf("%d",errno)-->errno 2
        exit(EXIT_FAILURE);
    }  
    
    write(fd,buf,sizeof(buf));              //write on file descripter thru buffer
    close(fd);
}