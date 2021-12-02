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
    FILE *f1,*f2;
    int i;
    int fd_r;                                   //rturn type open()-->int
    int fd_w;
    for(i=1;i<argc;i++)
    {
        //printf("$$ ",argv[i]);
        f1=argv[i];
        f2=argv[i+1];
    
    fd_r=open(f1,O_RDWR,S_IRUSR | S_IWUSR);           //file descripter user read write only
    
   
    
    if (fd_r == -1)
    {
        perror("error-->Source not present \n");              //printf("%d",errno)-->errno 2
        printf("%d",errno);
        exit(EXIT_FAILURE);
    
    }  
   
    fd_w=open(f2,O_WRONLY,S_IRUSR|S_IWUSR);
    
    if (fd_w == -1)
    {
        fd_w=open(f2,O_CREAT,S_IRUSR|S_IWUSR);
    
    }  
   //if(argv[1]=="dest.txt" && argv[2]=="src.txt")
    
     do{
    read(fd_r,buf,sizeof(buf));              //write on file descripter thru buffer
     }while(0);
    
    write(fd_w,buf,sizeof(buf));
    //printf("argv...%c\n",(char *)argv);
    close(fd_r);
    close(fd_w);
    }
}