#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	printf("Kill program start\n");
	printf("sleep 5s\n");
	sleep(5);

	int i;

	while(1)
	{
		for(i=0; i <5;i++)
		{
			printf("count: %d\n",i);
		}
	
		printf("killed process\n");
		kill(getpid(),SIGKILL);
		
	}
	return 0;
}

