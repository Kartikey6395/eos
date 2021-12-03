//comm btw two processes proc1 n proc2 using fifo
//code for proc1
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <stdio.h>
 #include <unistd.h>

int main(int argc,char const *argv[])
{
    int fd;
    fd=open("desdfifo",O_WRONLY);
    write(fd,"proc1 data\n",11);
    close(fd);
    return 0;

}