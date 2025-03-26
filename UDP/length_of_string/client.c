# include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

void main()
{
    int  client_fd;
    struct sockaddr_in client;
    socklen_t addr_len = sizeof(client);
    char buffer[1024];
    char *ip="127.0.0.1";
    int n;

     client_fd=socket(AF_INET,SOCK_DGRAM,0);
    if ( client_fd<0) perror("Error");

    client.sin_family=AF_INET;
    client.sin_port=htons(8001);
    client.sin_addr.s_addr=inet_addr(ip);


    while(1)
    {
        printf("\nEnter the String: ");
        scanf("%s",buffer);
        sendto(client_fd,buffer,sizeof(buffer),0,(struct sockaddr *)&client,addr_len);
        bzero(buffer,1024);
        recvfrom(client_fd, buffer, 1024, 0,(struct sockaddr *)&client,&addr_len);
        printf("%s",buffer);
    }
    close(client_fd);

}