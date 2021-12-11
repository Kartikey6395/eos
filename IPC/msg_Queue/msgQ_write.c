#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>  

#include <mqueue.h>

struct mq_attr cdacmq_attr;
mqd_t cdacmq;
int main(int argc,const char *argv[])
{
    cdacmq_attr.mq_flags=0;
    cdacmq_attr.mq_maxmsg = 4;
    cdacmq_attr.mq_msgsize = 128;
    cdacmq_attr.mq_curmsgs = 0;

    cdacmq= mq_open("/cdacmq",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR,&cdacmq_attr);

    mq_send(cdacmq,"DESD_HYD \n",10,0);
    mq_close(cdacmq);
    return 0;
    
}