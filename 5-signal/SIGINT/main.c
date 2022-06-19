#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void sig_handle(int num)
{
	printf("I'm sigle handle 1, num = %d\n",num);
	exit(EXIT_SUCCESS);
}


void sig_handle2(int num)
{
	printf("i'm signal handler 2, num = %d\n",num);
	exit(EXIT_SUCCESS);
}


void sig_handle3(int num)
{
	printf("i'm signal handler 3, num = %d\n",num);
	exit(EXIT_SUCCESS);
}
int main(int argc, char*argv[])
{
	if(signal(SIGINT,sig_handle) == SIG_ERR)
	{
		fprintf(stderr,"cannot handle sigint\n");
		exit(EXIT_FAILURE);
	}
	signal(SIGKILL,sig_handle2);
	signal(SIGTERM,sig_handle3);
	sleep(5);
	kill(getpid(),SIGINT);
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}

	return 0;
}
