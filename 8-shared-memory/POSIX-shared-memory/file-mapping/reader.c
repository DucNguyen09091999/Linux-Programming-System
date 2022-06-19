#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#define SHARED_MEM_SIZE 100
#define FILE_NAME "duc-map"

int main()
{
	/*create shared mem size*/
	int fd = shm_open(FILE_NAME, O_RDWR,0);

	if(fd < 0)
	{	
		printf("shm_open() is failed, %s.\n",strerror(errno));
		return -1;
	}
	/*declare size for smz*/
	ftruncate(fd,SHARED_MEM_SIZE);
	/*map/unmap*/
	char *data = (char*) mmap(0,SHARED_MEM_SIZE,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
	printf("%s: Read data: %s\n",__FILE__,data);
	munmap(data,SHARED_MEM_SIZE);
	close(fd);
	
	//shm_unlink(FILE_NAME);
	return 0;
}
