#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/file.h>
#include <stdlib.h>
int main()
{
	int fd;
	char text[50] = {0};
	int read_data;
	fd =open("myfile.txt",O_RDWR,0667);
	if(fd == -1)
	{
		printf("Can't open myfile.txt\n");
		exit(1);
	}
	else
	{
		printf("Open myfile.txt\n");
	}

	
	//locking file
	if(flock(fd, LOCK_EX | LOCK_SH) == -1)
	{
		printf("Can't get write lock\n");
	}


	if(flock(fd, LOCK_SH | LOCK_NB) == -1)
	{
		printf("Can't get read lock\n");
	}

	else
	{
		printf("Get read lock file\n");
		read_data = read(fd,text,sizeof(text));
		if(read_data == -1)
		{
			printf("Can't read file\n");
			exit(1);
		}
		else
		{
			printf("%s\n",text);
		}
	}


	close(fd);

	return 0;
}

