#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define LISTEN_BACKLOG 50
#define BUFF_SIZE 256
#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

/*chat function*/

void chat_func(int new_socket_fd)
{
	int num_read, num_write;
	char sendbuff[BUFF_SIZE];
	char recvbuff[BUFF_SIZE];

	while(1)
	{
		memset(senudbuff,'0',BUFF_SIZE);
		memset(recvbuff,'0',BUFF_SIZE);

		/*read data from socket*/
		/*read function will be blocked until they read data*/
		num_read = read(new_socket_fd,recvbuff,BUFF_SIZE);
		if(num_read == -1)
		{
			handle_error("read()");
			
		}
		
		if(strncmp("exit",recvbuff,4) == 0)
		{
			system("clear");
			break;
		}
		
		printf("\nMessage from client: %s\n",recvbuff);
		
		/*fill response from keyboard*/
		printf("Please response the message: ");
		fgets(sendbuff,BUFF_SIZE,stdin);
	
		/*write data into client by using write function*/
		num_write = write(new_socket_fd,sendbuff,sizeof(sendbuff));
		if(num_write == 1)
		{
			handle_error("write()");
		}

		if(strncmp("exit",sendbuff,4) == 0)
		{
			system("clear");
			break;
		}
		sleep(1);
		
	}
	close(new_socket_fd);
}


int main(argc, char *argv[])
{
	int port_no, len,opt_no;
	int server_fd, new_socket_fd;
	struct sockaddr_in ,serv_addr,client_addr;
	
	/*read portnumber in command line*/
	if(argc < 2)
	{
		printf("No port provided\ncommand: ./server <port number>\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		port_no = atoi(argv[1]);
	}

	memset(&serv,addr, 0, sizeof(struct sockaddr_in));
	memset(&client_addr,0,sizeof(struct sockaddr_in));

	/*create socket*/
	server_fd = socket(AFINET,SOCK_STREAM,0);
	if(server_fd == -1)
	{
		handle_error("socket()");
		fprintf(stderr, "ERROR on socket() : %s\n",strerror(errno));

	}
	/*band:"address already in use*/
	if(setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR,SO_REUSEPORT,&opt,sizeof(opt)))
	{
		handle_error("setsockopt()");
	}
	
	/*declare address for server*/
	serv.addr.sin_family = AF_INET;
	serv.addr.sin_port = htons(port_no);
	serv.addr.sin_addr.s_addr = INADDR_ANY; /*inet_addr("192.168.153.130"); //INADDR_ANY*/
	
	/*assign socket with server address*/
	if(bind(server_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) == -1)
	{
		handle_error("blind()");
	} 
	
	/*listen 5 char maximum in stack*/
	if(listen(server_fd,LISTEN_BACKLOG) == 1)
	{
		handle_error("listen()");
	}

	/*get client  information*/
	len = sizeof(client_addr);

	while(1)
	{
		printf("server is listening at port: %d \n...\n",port_no);
		new_socket_fd = accept(server_fd,(struct sockaddr *)&client_addr,(socklen_t*)&len);
		if(new_socket_fd == -1)
		{
			handle_error("accept()");
			system("clear");
		}

		char temp[BUFF_SIZE];
		inet_ntop(client_addr.sin_family,(struct sockaddr*)&client_addr,temp,sizeof(temp));
		printf("Server: got connection\n");
		chat_func();
		
	} 
	
	close(server_fd);
	return 0;
	
}





