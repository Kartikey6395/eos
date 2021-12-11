
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>  

#include <mqueue.h>

struct mq_attr cdacmq_attr;
int msg_prio;
char buff[100];

mqd_t cdacmq;
int main(int argc,const char *argv[])
{
    cdacmq_attr.mq_flags=0;
    cdacmq_attr.mq_maxmsg = 4;
    cdacmq_attr.mq_msgsize = 128;
    cdacmq_attr.mq_curmsgs = 0;

    cdacmq= mq_open("/cdacmq",O_RDONLY|O_CREAT,S_IRUSR|S_IWUSR,&cdacmq_attr);
    mq_receive(cdacmq,buff,128,&msg_prio);
    printf("%s->msg _prio--> %d ->buff",buff,msg_prio);

    //mq_send(cdacmq,"DESD_HYD \n",10,0);
    mq_close(cdacmq);
    return 0;
    
}