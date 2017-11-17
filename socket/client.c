#include<stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
	struct sockaddr_in server;
	int sockfd;
	socklen_t serverlen;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_port=htons(9800);
	serverlen=sizeof(server);
	connect(sockfd,(struct sockaddr*)&server,serverlen);
	char msg[128];
	while(1)
	{
		gets(msg);
		send(sockfd,msg,sizeof(msg),0);
	}
}
	
