#include <stdlib.h>     // standard stuff
#include <sys/mman.h>   // mmap()
#include <stdio.h>      // io stuff
#include <unistd.h>     // sleep()
#include <semaphore.h>  // semaphore()
#include <time.h>       // time()

#define BUFF_SIZE 10

int main(int argc, char*argv[]){
    //Create shared memory
    int *buffer = (char*)mmap(NULL,sizeof(int)*BUFF_SIZE, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);

    /*Create shared semaphores */
    sem_t *mutex = (sem_t*)mmap(NULL, sizeof(sem_t*), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    sem_t *empty = (sem_t*)mmap(NULL, sizeof(sem_t*), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    sem_t *full = (sem_t*)mmap(NULL, sizeof(sem_t*), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    sem_init(mutex,1,1);
    sem_init(empty,1,BUFF_SIZE);
    sem_init(full,1,0);
    /*Forking child process */
    pid_t producer;
    pid_t consumer;

    if((producer = fork()) == 0){
        while(1){
            sem_wait(empty);
            sem_wait(mutex);

            printf("Producer creates something\n");
            
            sem_post(full);
            sem_post(mutex);

            /*sleep between 0 and 3 second */
            srand(time(NULL));
            sleep(rand() %5);
        }
    }

    if((consumer = fork()) == 0){
        while(1){
            sem_wait(full);
            sem_wait(mutex);
            printf("Consumer take something\n");   
            sem_post(mutex);
            sem_post(empty);

            srand(time(NULL));
            sleep(3+rand() % 5);
        }
    }

    /* Parent */
    else {
        while(1){
            sleep(10);
            int takenslot;
            sem_getvalue(full,&takenslot);
            printf("Items in the buffer: %d/%d\n", takenslot,BUFF_SIZE);
        }
    }
}
