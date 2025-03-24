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
  socklen_t addr_size = sizeof(addr);     
  char buffer[1024];       
  int n;                   

  // Create a UDP client socket
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0){
    // Handle socket creation error
    perror("[-]Socket error");  
    exit(1);                    
  }
  printf("[+]UDP client socket created.\n");  

  // Initialize the server address structure
  memset(&addr, 0, sizeof(addr));  
  addr.sin_family = AF_INET;       
  addr.sin_port = port;            
  addr.sin_addr.s_addr = inet_addr(ip);

  // Continuously send and receive data with the server
  while(1){
    // Clear the buffer for new input
    bzero(buffer, 1024);
    printf("Enter Number: ");  
    fgets(buffer, 1024, stdin);  
    printf("Client: %s\n", buffer);  
    // Send the input to the server
    sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&addr, addr_size);
    // Clear the buffer for server response
    bzero(buffer, 1024);
    // Receive the server response
    recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addr_size);
    printf("Server: %s\n", buffer);  
  }

  // Close the socket
  close(sock);
  printf("Disconnected from the server.\n");  

  return 0;
}