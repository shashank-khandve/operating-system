#include<stdio.h>
#include <unistd.h>            
#include <fcntl.h>              
#include <sys/types.h>
#include <sys/stat.h>
char buffer[128]={0},buffer1[128]={0};
int main()
{
	int fd,fd1;
	while(1)
	{
		fd=open("dos",O_RDWR );
		read(fd,buffer,128);
		printf("reader:%s",buffer);
		close(fd);
		
	
	}
	return 0;
}
