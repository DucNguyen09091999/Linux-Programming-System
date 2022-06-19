#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define msg_size 20

char *msg1 = "Hello World #1";
char *msg2 = "Hello World #2";
char *msg3 = "Hello World #3";
int main(void)
{
    int fds[2];
    char buff_pipe[msg_size];
    if(pipe(fds) <  0)
    {
        printf("Pipes unsuccessfully\n");
        return -1;
    }

    write(fds[1],msg1,msg_size);
    write(fds[1],msg2,msg_size);
    write(fds[1],msg3,msg_size);

    for(int i=0; i <= 2 ;i++)
    {
        read(fds[0],buff_pipe,msg_size);
        printf("msg[%d] = %s\n",i+1,buff_pipe);
    }

    return 0;

}