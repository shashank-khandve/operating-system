#include<stdio.h>
#include<sys/mman.h>
#include<pthread.h>
#include<sys/stat.h>        /* For mode constants */
#include<fcntl.h> 
#include<unistd.h>
/*       void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);*/


int *count;
int main()
{
	int fd;
	fd=shm_open("shared element",O_CREAT | O_RDWR,0600);
	ftruncate(fd,sizeof(int *));
		
	
	count=mmap(NULL,sizeof(int *),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
	//printf("%d\n",*count);
	*count=22;	
	sleep(6);

	shm_unlink("shared element");
	return 0;
	
}
