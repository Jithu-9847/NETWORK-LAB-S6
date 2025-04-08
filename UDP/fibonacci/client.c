#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void main()
{
	int client_fd;
	struct sockaddr_in client;
	char buffer[1024];
	int port=8080;
	char *ip="127.0.0.1";
	socklen_t addr_len;
	
	client.sin_family=AF_INET;
	client.sin_port=htons(port);
	client.sin_addr.s_addr=inet_addr(ip);
	
	
	client_fd =socket(AF_INET,SOCK_DGRAM,0);
	printf("[-]Socket Created\n");

	addr_len=sizeof(client);
	while(1)
	{
		
		printf("Enter the limit for the fibinacci series : ");
		scanf("%s",buffer);
		sendto(client_fd,buffer,1024,0,(struct sockaddr *)&client,addr_len);
		
		while(1)
		{
			recvfrom(client_fd,buffer,1024,0,(struct sockaddr *)&client,&addr_len);
			if(strcmp(buffer,"END")==0)
			{
				break;
			}
			else{
			printf("%s\n",buffer);
			
			}
		}
	}
	
	close(client_fd);
	
}
