#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
        int fd;
        int read_num, write_num;
        char buf[20] = "Hello World!\n";

        fd = open("myfile.txt",O_CREAT | O_TRUNC | O_RDWR,0667);

        if(fd == -1)
        {
                printf("failed to open or create a file! error215549\n");
                exit(1);
        }
	else
	{
		printf("open file.txt\n");
	
	}


        write_num = write(fd,buf,strlen(buf));
        printf(" Write %d to hello.txt\n",write_num);

//lseek(fd,5,SEEK_SET);
// write(fd," my",strlen(" my"));

        close(fd);

        return 0;


}

