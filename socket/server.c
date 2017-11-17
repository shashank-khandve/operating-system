#include<stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
	struct sockaddr_in server,client;
	int sockfd,clientfd;
	int serverlen,clientlen;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	server.sin_port=htons(9800);
	
	serverlen=sizeof(server);
	
	int ret=bind(sockfd,(struct sockaddr*)&server,serverlen);
	if(ret==-1)
		perror("error");
	listen(sockfd,5);
	
	clientfd=accept(sockfd,(struct sockaddr*)&client,&clientlen);
	char msg[128];
	
	while(1)
	{
		recv(clientfd,msg,128,0);
		printf("recieved msg::%s\n",msg);
	}
	//close(sockfd)
}
