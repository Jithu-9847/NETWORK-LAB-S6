#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void main()
{
	int server_fd,client_fd;
	struct sockaddr_in server,client;
	char buffer[1024];
	int port=8080;
	socklen_t addr_len;
	
	server.sin_family=AF_INET;
	server.sin_port=htons(port);
	server.sin_addr.s_addr=INADDR_ANY;
	
	
	server_fd =socket(AF_INET,SOCK_DGRAM,0);
	printf("[-]Socket Created\n");
	bind(server_fd,(struct sockaddr *)&server,sizeof(server));
	printf("[-]Binded\n");
	addr_len=sizeof(client);
	while(1)
	{
		recvfrom(server_fd,buffer,1024,0,(struct sockaddr *)&client,&addr_len);
		printf("%s\n",buffer);
		int n=atoi(buffer);
		for(int i=0;i<n;i++)
		{
		int fib=fibonacci(i);
		
		sprintf(buffer,"%d",fib);
		sendto(server_fd,buffer,1024,0,(struct sockaddr *)&client,addr_len);
		}
		sendto(server_fd,"END",strlen("END"),0,(struct sockaddr *)&client,addr_len);
	}
	
	close(server_fd);
	
}
