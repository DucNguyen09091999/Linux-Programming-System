#include <stdio.h>
#include<stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define SHARED_MEM_SIZE	100 /*size of shared memory object in bytes)*/
#define FILE_NAME	"duc-map"

int main()
{
	int shm_fd = shm_open(FILE_NAME,O_CREAT | O_RDWR , 0666);
	if(shm_fd < 0)
	{
		printf("shm_open() is failed, error: %s.\n",strerror(errno));
		return -1;

	}

	/*set size*/
	ftruncate(shm_fd,SHARED_MEM_SIZE);

	/* Map/Unmap */

	char *data = (char*)mmap(0,SHARED_MEM_SIZE, PROT_READ | PROT_WRITE,MAP_SHARED,shm_fd,0);
	strcpy(data,"MMAP Hello World !");
	printf("%s: Write data	: %s \n",__FILE__,data);
	
	munmap(data,SHARED_MEM_SIZE);
	close(shm_fd);
	return 0;
}
