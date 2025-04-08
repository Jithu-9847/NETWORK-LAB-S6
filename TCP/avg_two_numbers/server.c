#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>


void main()
{
	int port=3000;
	int server_fd,client_fd;
	struct sockaddr_in server,client;
	char buffer[1024];
	socklen_t addr_len;
	int num1,num2;
	server_fd=socket(AF_INET,SOCK_STREAM,0);
	
	server.sin_family=AF_INET;
	server.sin_port=htons(port);
	server.sin_addr.s_addr=INADDR_ANY;
	
	bind(server_fd,(struct sockaddr *)&server,sizeof(server));
	printf("Listening...\n");
	listen(server_fd,2);
	addr_len=sizeof(client);
	client_fd=accept(server_fd,(struct sockaddr *)&client,&addr_len);
	
	
	
	while(1)
	{
		bzero(buffer,1024);
		recv(client_fd,buffer,1024,0);
		num1=atoi(buffer);
		
		bzero(buffer,1024);
		recv(client_fd,buffer,1024,0);
		num2=atoi(buffer);
		
		sprintf(buffer,"%d",((num1+num2)/2));
		printf("%s\n",buffer);
		send(client_fd,buffer,1024,0);
	}
	close(client_fd);	
}
