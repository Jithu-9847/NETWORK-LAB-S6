#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

 
void main()
{
	int server_fd,client_fd;
	struct sockaddr_in server,client;
	socklen_t addr_len;
	int port=8080;
	char buffer[1024];
	FILE *f1;
	addr_len=sizeof(client);
	
	server_fd=socket(AF_INET,SOCK_STREAM,0);
	printf("[-]Socket Created\n");
	
	server.sin_family=AF_INET;
	server.sin_port=htons(port);
	server.sin_addr.s_addr=INADDR_ANY;
	
	bind(server_fd,(struct sockaddr *)&server,sizeof(server));
	printf("[-]Binded\n");
	
	printf("[-]Listening...\n");
	listen(server_fd,2);
	
	client_fd=accept(server_fd,(struct sockaddr *)&client,&addr_len);
	printf("[-]Client Connected \n");
	
	
	 while(1)
	 {
		recv(client_fd,buffer,1024,0);
		
		f1=fopen(buffer,"r");
		
		bzero(buffer,1024);
		
		fgets(buffer,1024,f1);
		
		send(client_fd,buffer,sizeof(buffer),0);
		
		 
	}	
	 
	printf("[-]Client Exited!");
	close(client_fd);
}
