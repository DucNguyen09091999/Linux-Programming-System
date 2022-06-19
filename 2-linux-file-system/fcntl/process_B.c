#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd;
	char text[15] = {0};
	struct flock fl;


	sprintf(text,"nguyenchiduc");
	if((fd == open("./myfile.txt",O_RDWR)) == -1)
	{
		printf("Can't open file\n");
		exit(1);
	}
	else
	{
		printf("Open file successfully\n");
	}

	fl.l_start = 1;
	fl.l_len =5;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
		
	if(fcntl(fd,F_SETLK,&fl) == -1)
	{
		printf("Can't set write lock byte 1 - 5\n");
	}
	else
	{
		printf("set write byte 1 - 5 successfully\n");
	}

	fl.l_start = 6;
	fl.l_len = 8;
	fl.l_type = F_WRLCK;
	fl.l_whence = SEEK_SET;
	
	if(fcntl(fd,F_SETLK,&fl) == -1)
	{
		printf("Can't set write lock bytes 6 -11\n");
	}
	else
	{
		printf("Set write lock 6 -11\n");
		lseek(fd,6,SEEK_SET);
		
		if(write(fd,text,sizeof(text)) == -1)
		{

			printf("Can't write file\n");
			exit(1);
		}
		else
		{
			printf("Write file\n");
		}
	}

	

	close(fd);
	return 0;


}

