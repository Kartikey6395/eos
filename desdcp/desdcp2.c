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
    
    fd_r=open("source.txt",O_RDWR,S_IRUSR | S_IWUSR);           //file descripter user read write only
    
   
    
    if (fd_r == -1)
    {
        perror("error-->Source not present \n");              //printf("%d",errno)-->errno 2
        printf("%d",errno);
        exit(EXIT_FAILURE);
    
    }  
   
    fd_w=open("destn.txt",O_WRONLY,S_IRUSR|S_IWUSR);
    
    if (fd_r == -1)
    {
        fd_w=open("destn.txt",O_CREAT,S_IRUSR|S_IWUSR);
    
    }  
    if(argv[1]=="destn.txt" && argv[2]=="source.txt")
    {
     do{
    read(fd_r,buf,sizeof(buf));              //write on file descripter thru buffer
     }while(0);
    
    write(fd_w,buf,sizeof(buf));
    //printf("argv...%c\n",(char *)argv);
    close(fd_r);
    close(fd_w);
    }
}