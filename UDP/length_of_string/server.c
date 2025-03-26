#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

FILE *f1;

void main()
{
    int server_fd, client_fd;
    struct sockaddr_in server, client;
    socklen_t addr_len = sizeof(client);
    char buffer[1024];
    int n;

    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd < 0)
        perror("Error");

    server.sin_family = AF_INET;
    server.sin_port = htons(8001);
    server.sin_addr.s_addr = INADDR_ANY;

    n = bind(server_fd, (struct sockaddr *)&server, sizeof(server));
    if (n < 0)
        perror("Error");
    printf("Binded Successfully...\n");

    //code for finding number of length of a string
    while (1)
    {
        recvfrom(server_fd, buffer, 1024, 0,(struct sockaddr *)&client,&addr_len);
        int len=printf("%s\n",buffer);
        sprintf(buffer,"%i",len-1);
        sendto(server_fd,buffer,sizeof(buffer),0,(struct sockaddr *)&client,addr_len);
    }
    
    close(client_fd);
    printf("Client Exited...\n");
}