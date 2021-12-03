//open file and write-->user req to kernell via sys call
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h> 

int main(int argc,char const *argv[])
{   
    char buf[50];
    
    int fd_r;                                   //rturn type open()-->int
    int fd_w;
    
    fd_r=open("fsource.txt",O_RDWR | O_CREAT,S_IRUSR | S_IWUSR);           //file descripter user read write only
    
   
    
    if (fd_r == -1)
    {
        perror("error-->Source not present \n");              //printf("%d",errno)-->errno 2
        printf("%d",errno);
        exit(EXIT_FAILURE);
    
    }  
    
    read(fd_r,buf,sizeof(buf));              //write on file descripter thru buffer
    
    fd_w=open("fdestn.txt",O_WRONLY | O_CREAT,S_IRUSR|S_IWUSR);
    
    /*if (fd_r == -1)
    {
        perror("error-->file not present \n");              //printf("%d",errno)-->errno 2
        printf("%d",errno);
        exit(EXIT_FAILURE);
    
    }  */
    
    write(fd_w,buf,sizeof(buf));
    
    close(fd_r);
    close(fd_w);
}