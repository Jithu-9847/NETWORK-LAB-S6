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
    server.sin_addr.s_addr = INADDR_ANY;

    int a=bind(server_fd, (struct sockaddr*)&server, sizeof(server));
    printf("Listening...\n");
    listen(server_fd, 2);
    
    addr_len = sizeof(client);
    client_fd = accept(server_fd,(struct sockaddr *)&client, &addr_len);
    
    printf("Accepted...\n");
  
    while(1)
    {
        recv(client_fd,buffer,sizeof(buffer),0);
        int num;
        num=atoi(buffer);
        char res[100];
        sprintf(res,"%s",num & 1 ? "Odd":"Even");
        send(client_fd,res,sizeof(res),0);
    }

    close(client_fd);
    printf("[+]Client disconnected.\n\n");

    return 0;
}
