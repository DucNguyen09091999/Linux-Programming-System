#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define BUFF_SIZE 100

struct message_buffer {
    long mesg_type;
    char mesg_text[BUFF_SIZE];
} message;

int main(int argc ,char*argv[]){
    key_t key;
    int msgid;
    key = ftok("profile",65);

    /*Create message */
    msgid = msgget(key, 0666 | IPC_CREAT);

    /* Receive data */
    msgrcv(msgid,&message,sizeof(message),1,0);

    /* Printf data */
    printf("Data received is %s\n",message.mesg_text);

    /* Remove message queues */

    msgctl(msgid,IPC_RMID,NULL);
    return 0;
}