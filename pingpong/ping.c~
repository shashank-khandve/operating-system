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
sem_t *sem1,*sem2;
FILE *a;
FILE *b;
int *buffer1,*buffer2;
void *writeThread(void *data)
{
	while(1)
	{
		sem_wait(&sem1);
		write(a,buffer1,128);
		sem_post(&sem2);
		
		sem_wait(&sem2);
		write(b,buffer2,128);
		sem_post(&sem1);
	}
}
int main()
{
	int fd1,fd2;
	fd1=shm_open("/shared element1",O_CREAT | O_RDWR,0600);
	ftruncate(fd1,sizeof(int *));
	buffer1=mmap(NULL,sizeof(int *),PROT_READ | PROT_WRITE,MAP_SHARED,fd1,1);
	
	fd2=shm_open("/shared element2",O_CREAT | O_RDWR,0600);
	ftruncate(fd2,sizeof(int *));
	buffer2=mmap(NULL,sizeof(int *),PROT_READ | PROT_WRITE,MAP_SHARED,fd2,0);
	//return 0;
	a=fopen("data1.txt",r);
	b=fopen("data2.txt",r);
	pthread_t writeTid;
	sem1=sem_open("/write1",O_CREAT|O_RDWR,S_IWUSR|S_IRUSR,1);
	sem2=sem_open("/write2",O_CREAT|O_RDWR,S_IWUSR|S_IRUSR,0);
	pthread_create(&writeTid,NULL,writeThread,NULL); 
	pthread_join(writeTid,NULL);
	return 0;
}
