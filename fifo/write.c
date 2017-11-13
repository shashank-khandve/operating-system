#include<stdio.h>
#include <unistd.h>            
#include <fcntl.h>              
#include <sys/types.h>
#include <sys/stat.h>
char buffer[128]={0},buffer1[128]={0};
int main()
{
	int fd,fd1;
	mkfifo ("linkfifo",S_IRUSR|S_IWUSR);
	while(1)
	{
		fd=open("linkfifo",O_RDWR );
		read(0,buffer,128);
		write(fd,buffer,128);
		close(fd);
		
		
	}
	return 0;
}





