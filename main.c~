#include<stdio.h>
#include <unistd.h>            
#include <fcntl.h>              
#include <sys/types.h>
#include <sys/stat.h>
unsigned char buffer[128];
int main()
{
	int fd;
	//mkfifo("dssd",I_);
	fd=open("desd",O_RDWR);
	if(fd==0)
		perror("interrupts occurred\n");
	read(fd,buffer,128);
	printf("reader:%s \nsent by wrietr\n",buffer);
	close(fd);
	return 0;
}
