#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(int argc, char*argv[])
{
	/*
		@brief shared memory key
		create key 
	*/
	key_t key = ftok("./shmfile",65);
	

	/*Set up shared memory segment*/
	int shmid = shmget(key,1024,0666 | IPC_CREAT);

	/*attact/detact (map/unmap) */
	char *str = (char*)shmat(shmid,(void*)0,0);

	printf("Message to shared memory: ");
	fgets(str,1024,stdin);
	shmdt(str);


	
}
