#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
# include <unistd.h>

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server, client;
    socklen_t addr_len;
    char buffer[1024];
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8001);
    server.sin_addr.s_addr =inet_addr("127.0.0.1");

    connect(server_fd,(struct sockaddr *)&server,sizeof(server));
    printf("Accepted...\n");
    while(1)
    {
        printf("Enter the Number:");
        scanf("%s",buffer);
        send(server_fd,buffer,sizeof(buffer),0);
        bzero(buffer,1024);
        recv(server_fd,buffer,sizeof(buffer),0);
        printf("%s\n",buffer);
    }
    close(server_fd);
    printf("client closed connection");
    return 0;
}
