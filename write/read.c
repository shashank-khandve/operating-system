#include <unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include <errno.h>
 int main( )
 {
 	int fd,fd1,fd2,fd3;
 	char arr[15];
 	fd=open("test.text",O_RDWR);
 	if(fd==-1)
 		perror("error while opening\n");
 	else
 		fd1=read(fd,arr,15);
 	if(fd1==-1)
 		perror("error while reading\n");
 	else 
	 	fd3=open("test1.c",O_CREAT|O_RDWR,S_IRWXU|S_IRWXG| S_IRWXO );
 	fd2=write(fd3,arr,15);
 	if(fd2==-1)
 		perror("error while writing\n");
 	close(fd);
 	return 0;
 }
