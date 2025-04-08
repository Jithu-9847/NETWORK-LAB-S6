#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>


void main()
{
	int port=3000;
	char *ip="127.0.0.1";
	int client_fd;
	struct sockaddr_in client;
	char buffer[1024];
	socklen_t addr_len;
	
	client_fd=socket(AF_INET,SOCK_STREAM,0);
	
	client.sin_family=AF_INET;
	client.sin_port=htons(port);
	client.sin_addr.s_addr=inet_addr(ip);
	
	
	connect(client_fd,(struct sockaddr *)&client,sizeof(client));
	
	addr_len=sizeof(client);
	
	while(1)
	{
		bzero(buffer,1024);
		printf("Enter the First Number:");
		scanf("%s",buffer);
		send(client_fd,buffer,1024,0);
		
		bzero(buffer,1024);
		printf("Enter the Second Number:");
		scanf("%s",buffer);
		send(client_fd,buffer,1024,0);
		
		recv(client_fd,buffer,1024,0);
		printf("The average of the two numbers are :%s\n",buffer);
	}
	close(client_fd);	
}
