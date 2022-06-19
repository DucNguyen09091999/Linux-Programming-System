#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>
#include <string.h>
#define MQUEUE_NAME "/mqueue"
#define MQUEUE_MODE (S_IRUSR | S_IWUSR)
int main(){
    mqd_t mqid;
    struct mq_attr attrp;
    printf("Create message queue\n");
    mqid = mq_open(MQUEUE_NAME,O_RDWR | O_CREAT | O_NONBLOCK,MQUEUE_MODE,NULL);
    if(mqid == -1){
        printf("mq_open() error no %d: %s\n",errno,strerror(errno));
        return -1;
    }

    // Get information into struct
    if(mq_getattr(mqid,&attrp) != 0){
        printf("mq_getattr() error no %d: %s\n",errno,strerror(errno));
        return -1;
    } 

    // Check flag
    if(attrp.mq_flags == 0){
        printf("0\n");
    } else {
        printf("O_NONBLOCK\n");

    }

    printf("mq_maxmsg = %ld\n",attrp.mq_maxmsg);
    printf("mq_msgize = %ld\n",attrp.mq_msgsize);
    printf("mq_curmsgs = %ld\n",attrp.mq_curmsgs);

    // unlink message queue
    mq_unlink(MQUEUE_NAME);

    return 0;
   
    
}