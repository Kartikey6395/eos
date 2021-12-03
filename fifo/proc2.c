//comm btw two processes proc1 n proc2 using fifo
//code fpr proc2
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <stdio.h>
 #include <unistd.h>

int main(int argc,char const *argv[])
{
    unsigned char buff[20];
    int fd;
    fd=open("desdfifo",O_RDONLY);
    read(fd,buff,11);
    close(fd);
    printf("buff read sucess---->> %s\n",buff);
    return 0;

}