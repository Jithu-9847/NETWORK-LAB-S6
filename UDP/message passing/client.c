#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    char *ip = "127.0.0.1";
    int port = 3001;

    int sock;
    struct sockaddr_in server_addr;
    socklen_t addr_size = sizeof(server_addr);
    char buffer[1024];
    int n;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    printf("[+]UDP client socket created.\n");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    while (1)
    {
        bzero(buffer, 1024);
        printf("Enter Message to the Server: ");
        fgets(buffer, 1024, stdin);
        if (strcmp(buffer, "EXIT\n") == 0)
            break;
        sendto(sock, buffer, strlen(buffer), 0,(struct sockaddr *)&server_addr, addr_size);
        bzero(buffer, 1024);
        n = recvfrom(sock, buffer, sizeof(buffer), 0,(struct sockaddr *)&server_addr, &addr_size);
        printf("Server: %s\n", buffer);
    }

    close(sock);
    printf("[+]Client socket closed.\n");

    return 0;
}
