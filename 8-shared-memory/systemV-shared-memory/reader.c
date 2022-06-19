#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234

int main()
{
	key_t key = ftok("./shmfile",65);
	
	int shmid = shmget(key,1024,0666 | IPC_CREAT);

	char *shmaddr = (char*)shmat(shmid,(void*)0,0);
	printf("Data read from memory: %s\n",shmaddr);
	shmdt(shmaddr);


	//shmctl(shmid,IPC_RMID,NULL);

	return 0;
}
