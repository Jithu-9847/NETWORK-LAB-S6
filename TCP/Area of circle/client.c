#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void main()
{
	int client_fd;
	struct sockaddr_in client;
	socklen_t addr_len;
	int port=8080;
	char *ip="127.0.0.1";
	char buffer[1024];
	
	addr_len=sizeof(client);
	
	client_fd=socket(AF_INET,SOCK_STREAM,0);
	printf("[-]Socket Created\n");
	
	client.sin_family=AF_INET;
	client.sin_port=htons(port);
	client.sin_addr.s_addr=inet_addr(ip);
	
	 
	
	connect(client_fd,(struct sockaddr *)&client,addr_len);
	printf("[-]Client Connected \n");
	
	
	while(1)
	{
		
		
		printf("Enter the radius of the circle : ");
		scanf("%s",buffer);
		send(client_fd,buffer,1024,0);
		
		recv(client_fd,buffer,1024,0);
		printf("\nThe Area of the circle is :%s\n",buffer);
	}
	printf("[-]Client Exited!");
	close(client_fd);
}
