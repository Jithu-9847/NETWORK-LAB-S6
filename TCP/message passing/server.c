#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int port = 3001;
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    printf("[+]TCP server socket created.\n");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    n = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("[+]Bind to the port number: %d\n", port);

    listen(server_sock, 5);
    printf("Listening...\n");

    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);
    printf("[+]Client connected.\n");

    while (1)
    {
        bzero(buffer, 1024);
        recv(client_sock, buffer, 1024, 0);
        if (strcmp(buffer, "EXIT\n") == 0)
            break;
        printf("Message from client: %s\n", buffer);
        bzero(buffer, 1024);
        printf("Enter the message to the Client: ");
        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        send(client_sock, buffer, strlen(buffer), 0);
    }

    close(client_sock);
    printf("[+]Client disconnected.\n\n");

    return 0;
}