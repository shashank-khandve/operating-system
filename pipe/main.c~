#include<stdio.h>
#include <unistd.h>              
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	pid_t id;
	int p,sum;
	int fd[2];
	int buffer[2]={10,20};	
	p=pipe(fd);
	id=fork();
	if(p==0)
	{
		if(id==0)
		{	
			int buffer1[2]={50,60};
			close(fd[1]);
			read(fd[0],buffer,2);
			printf("%d\n",buffer[0]+buffer[1]);
		}
		else
		{
			close(fd[0]);
			write(fd[1],buffer,2);
			close(fd[1]);
		}
	}
	return 0;
}


