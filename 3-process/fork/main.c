#include <stdio.h>
#include <unistd.h>

int main(int argc , char* argv[])		//cap phat stack frame cho ham main
{	
	/*code*/
	pid_t child_pid;			//Luu trong stack frame cua main
	int counter = 2;			//luu trong stack frame cua main
	
	printf("Initial value of counter is %d\n",counter);

	child_pid = fork();

	if(child_pid >= 0)
	{
		if(child_pid == 0)
		{			/*Process con*/
			printf("I'am the child process, counter: %d\n",++counter);
			printf("My PID is: %d, my parent PID is: %d\n",getpid(),getppid());
		}
		else
		{			/*Process cha*/
			printf("I'm the parent process, counter: %d\n",++counter);
			printf("my PID is: %d\n",getpid());
			while(1);
		}
	}
	
	else
	{				//fork return -1 neu loi 
		printf("fork unsuccessfully\n");
	}
	return 0;
	
}
