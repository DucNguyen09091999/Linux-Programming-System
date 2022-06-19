#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>




int main()
{
	
	int fd;
	int write_data;
	char text[20] = {0};

	struct flock fl;

	fd = open("myfile.txt", O_CREAT | O_RDWR , 0667);
	if(fd == -1)
	{
		printf("Can't open myfile.txt\n");
		exit(1);
	}
	else
	{
		printf("Open myfile.txt successfully\n");
	}
	
	
	sprintf(text,"Hello world\n");
	write_data =write(fd,text,sizeof(text));
	if(write_data == -1)
	{
		printf("Can't write data into myfile.txt\n");
		exit(1);
	}
	else
	{
		printf("Write data successfully\n");
	}


	fl.l_start = 1;			//Offset where the lock begins
	fl.l_len = 5;			//Number of bytes to lock; 0 means "until EOF"
	fl.l_type = F_WRLCK;		//Lock type: F_RDCLK,F_WRCLK,f_UNCLK
	fl.l_whence = SEEK_SET;		//How to interpret '1_star':SEEK_SET,SEEK_CUR, SEEK_END

	if(fcntl(fd,F_SETLK,&fl) == -1)
	{
		printf("Can't set write lock byte 1 - 5\n"); 
	}
	else
	{
		printf("Set write lock byte 1 - 5 \n");
	}
	
	while(1)
	{
		sleep(1);
	}


	close(fd);

	return 0;
}
