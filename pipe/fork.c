#include<stdio.h>
 #include <unistd.h>
int main()
{
	pid_t fd,fd1;
	fd=fork();
	fd1=fork();
	if(fd==0|fd1==0)
	{
		printf("if==%d:%d\n",getpid(),getppid());
		//printf("1");
		//printf("2");
		//printf("3");
	}
	else
	{
		printf("else==%d:%d\n",getpid(),getppid());
		//printf("4");	
		//printf("5");
		//printf("6");
	}
	return 0;
}
