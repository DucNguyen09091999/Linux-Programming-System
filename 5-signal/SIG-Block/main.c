#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#define __POSIX_SOURCE

void signal_handle(int num)
{
	printf("i'm handle 1, num = %d\n",num);
	exit(EXIT_SUCCESS);
}

int main(int argc, char*argv[])
{
	sigset_t new_set, old_set;
	if(signal(SIGINT,signal_handle) == SIG_ERR)
	{
		fprintf(stderr,"sigint error\n");
		exit(EXIT_FAILURE);
	}
	sigemptyset(&new_set);
	sigemptyset(&old_set);
	printf("new set is %x\n",new_set);
	printf("PID = %d\n",getpid());
	sigaddset(&new_set,SIGINT);	
	if(sigprocmask(SIG_SETMASK,&new_set,&old_set) == 0)
	{
		if(sigismember(&new_set,SIGINT) == 1)
		{
			printf("SIGINT is exist\n");
		}
		else if(sigismember(&old_set,SIGINT) == 0)
		{
			printf("SIGINT doesn't not exist\n");
		}
	}
	
	while(1);
	return 0;
}


