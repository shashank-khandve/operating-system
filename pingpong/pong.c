#include<stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include<fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include<sys/stat.h>     
#include <semaphore.h>
int main ()
{
	sem_t *semSHM,*semSHMW;
	int *data;
	int *tempBuffer;
	int fd,fdBuffer;

	semSHM=sem_open("semWrite1",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,0);
  	semSHMW=sem_open("semWrite2",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR,0);
	sem_init(semSHM,1,0);
	sem_init(semSHMW,1,0);

  	fd=shm_open("sharedMem",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	ftruncate(fd,sizeof(int*));
	data=mmap(NULL,sizeof(int*),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

  	fdBuffer=shm_open("sharedBuffer",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
  	ftruncate(fdBuffer,sizeof(int*));
  	tempBuffer=mmap(NULL,sizeof(int*),PROT_READ|PROT_WRITE,MAP_SHARED,fdBuffer,0);
	
	while(1)
	{

		sem_wait(semSHM);
  		printf("%d\n",*data);
  		//sem_post(semSHM);
		sem_wait(semSHMW);
		printf("%d\n",*tempBuffer);	
		//sem_post(semSHMW);
	}
	return 0;
}
