#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
  // Define the server IP address and port number
  char *ip = "127.0.0.1";  
  int port = 3001;         

  // Declare variables for socket creation and communication
  int sock;                
  struct sockaddr_in addr; 
  socklen_t addr_size;     
  char buffer[1024];       
  int n;                   

  // Create a TCP client socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    // Handle socket creation error
    perror("[-]Socket error");  
    exit(1);                    
  }
  printf("[+]TCP client socket created.\n");  

  // Initialize the server address structure
  memset(&addr, 0, sizeof(addr));  
  addr.sin_family = AF_INET;       
  addr.sin_port = port;            
  addr.sin_addr.s_addr = inet_addr(ip);

  // Establish a connection with the server
  int r = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
  
  printf("Connected to the server.\n");  

  // Continuously send and receive data with the server
  while(1){
    // Clear the buffer for new input
    bzero(buffer, 1024);
    printf("Enter Number: ");  
    fgets(buffer, 1024, stdin);  
    printf("Client: %s\n", buffer);  
    // Send the input to the server
    send(sock, buffer, strlen(buffer), 0);
    // Clear the buffer for server response
    bzero(buffer, 1024);
    // Receive the server response
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s\n", buffer);  
  }

  // Close the socket
  close(sock);
  printf("Disconnected from the server.\n");  

  return 0;
}