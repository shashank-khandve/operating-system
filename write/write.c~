#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
	pid_t fd;
	fd=open("test.text",O_CREAT|O_RDWR,S_IRWXU|S_IRWXG| S_IRWXO );
	//if(fd==-1)	
		//fd=creat("test.text",S_IXUSR|S_IRWXG| S_IRWXO );
	write(fd,"hello shubham\n",14);
	close(fd);
}
		
		
