#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Define the IP address and port number for the server
    int port = 3001;

    // Declare variables for the server and client sockets
    int server_sock, client_sock;

    // Declare structures for the server and client addresses
    struct sockaddr_in server_addr, client_addr;

    // Declare a variable to store the size of the client address
    socklen_t addr_size;

    // Declare a buffer to store incoming data from the client
    char buffer[1024];

    // Declare a variable to store the return value of the bind function
    int n;

    // Create a TCP server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    printf("[+]TCP server socket created.\n");

    // Initialize the server address structure
    memset(&server_addr,0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the specified port
    n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("[+]Bind to the port number: %d\n", port);

    // Listen for incoming connections from clients
    listen(server_sock, 5);
    printf("Listening...\n");

    // Accept an incoming connection from a client
    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
    printf("[+]Client connected.\n");

    // Continuously receive and process data from the client
    while (1) {
        // Clear the buffer to prepare for incoming data
        bzero(buffer, 1024);

        // Receive data from the client
        recv(client_sock, buffer, sizeof(buffer), 0);

        //include your logic here that the server will perform on the received data
        //here we are adding 1 to the received data

        // Convert the received data to an integer
        int num = atoi(buffer);
        num += 1;
        bzero(buffer, 1024);

        // Convert the integer to a string and store it in the buffer
        sprintf(buffer, "%d", num);

        // Send the data back to the client
        send(client_sock, buffer, sizeof(buffer), 0);
    }

    // Close the client socket
    close(client_sock);
    printf("[+]Client disconnected.\n\n");

    // Return 0 to indicate successful execution
    return 0;
}