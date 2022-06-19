#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>	

pthread_t thread_id1, thread_id2;

typedef struct
{
	char name[30];
	char msg[30];
}thr_data_t;

static void *thr_handle(void *args)
{
	pthread_t tid = pthread_self();
	thr_data_t *data = (thr_data_t *)args;
	if(pthread_equal(tid,thread_id1))
	{
		printf("I'm thread_id1\n");
		
	}
	else
	{
		printf("I'm thread_id2\n");
		printf("hello %s, welcome to join %s\n",data->name, data->msg);
	}
}

static void *thr_handle2(void *args)
	{
		printf("Hi i'm thread handle 2\n");
	}

int main(int argc , char* argv[])
{
	/*code*/
	int ret;
	thr_data_t data = {0};

	strncpy(data.name ,"nguyenchiduc99",sizeof(data.name));
	strncpy(data.msg,"KMA thread programming\n",sizeof(data.msg)); 

	if(ret = pthread_create(&thread_id1,NULL,&thr_handle,NULL))
	{
		printf("pthread_create() error number = %d\n",ret);
		return -1;
	}	
	
	sleep(2);
	if(ret = pthread_create(&thread_id2,NULL,&thr_handle,&data))
	{
		printf("pthread_create() error number = %d\n",ret);
		return -1;
	}		  

	sleep(5);

	return 0;
}
