#include<stdio.h>
#include <unistd.h>            
#include <fcntl.h>              
#include <sys/types.h>
#include <sys/stat.h>
char buffer[128];
int main()
{
	int fdfifo,fdfork;
	fdfifo=open("fork",O_RDWR);
	fdfork=fork();
	if(fdfork!=0)
		write(fdfifo,"shubham 007\n",12);
	else
		read(fdfifo,buffer,128);
	printf("%s",buffer);
	return 0;
}
