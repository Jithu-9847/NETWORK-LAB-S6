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

    // Create a UDP server socket
    server_sock = socket(AF_INET, SOCK_DGRAM, 0);
    printf("[+]UDP server socket created.\n");

    // Initialize the server address structure
    memset(&server_addr,0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the specified port
    n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("[+]Bind to the port number: %d\n", port);

    // Continuously receive and process data from the client
    while (1) {
        // Clear the buffer to prepare for incoming data
        bzero(buffer, 1024);

        // Receive data from the client
        addr_size = sizeof(client_addr);
        recvfrom(server_sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &addr_size);
        printf("[+]Data Received\n");

        // Convert the received data to an integer
        int num = atoi(buffer);
        num += 1;
        bzero(buffer, 1024);

        // Convert the integer to a string and store it in the buffer
        sprintf(buffer, "%d", num);

        // Send the data back to the client
        sendto(server_sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, addr_size);
    }

    // Close the server socket
    close(server_sock);
    printf("[+]Server stopped.\n\n");

    // Return 0 to indicate successful execution
    return 0;
}