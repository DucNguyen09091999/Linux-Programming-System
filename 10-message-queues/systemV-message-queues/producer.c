#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define BUFF_SIZE 100
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
}message;


int main(int argc, char *argv[]){

    key_t key;
    int msgid;
    /* Create a key */
    key = ftok("profile",65);

    /* Create a message queues */
    msgid = msgget(key,0666 | IPC_CREAT);

    /* Get message type */
    printf("Enter message type: ");
    scanf("%ld",&message.mesg_type);
    stdin = freopen(NULL,"r",stdin); //clear input buffer

    /* Get message data */
    printf("Enter message data: ");
    fgets(message.mesg_text , BUFF_SIZE,stdin);

    /*Send message */
    msgsnd(msgid,&message,sizeof(message),0);
    
    return 0;
    
}