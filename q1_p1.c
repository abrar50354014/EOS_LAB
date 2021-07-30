#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <mqueue.h>

mqd_t amq;
struct mq_attr amq_attr;


int main()
{  amq_attr.mq_flags = 0;
    amq_attr.mq_maxmsg = 10;
    amq_attr.mq_msgsize = 128;
    amq_attr.mq_curmsgs = 0;

    amq = mq_open("/usr/share/dictionary", O_WRONLY | O_CREAT,S_IRUSR | S_IWUSR, &amq_attr);

    mq_send(amq, "m\n",2,0 );


    mq_close(amq);
    return 0;

}
