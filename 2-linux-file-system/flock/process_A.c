#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
int main(void)
{
	
	int fd;
	char text[50] = {0};
	int write_data;
	fd = open("myfile.txt", O_CREAT | O_RDWR | O_TRUNC , 0667);
	
	//Create myfile.txt
	if(fd == -1)
	{
		printf("Create myfile.txt fail\n");
		exit(1);
	}
	else
	{	printf("Create myfile.txt successfully\n");
		
	}


	//Write data into myfile.txt
	sprintf(text, "Hello everyone. Welcome to my world\n");
	write_data = write(fd, text,sizeof(text));
	if (write_data == -1)
	{
		printf("Can't read data\n");
	}
	else
	{
		printf("Write %d bytes to myfile.txt\n",write_data);
	}
	
	//flock function

	if(flock(fd,LOCK_SH)==-1)
	{
		printf("Can't set read lock\n");
	}
	else
	{
		printf("Set read lock\n");
	}
	
	while(1)
	{
		sleep(1);
	}	
	
	close(fd);
	return 0;
}
