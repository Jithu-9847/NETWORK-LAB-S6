#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
  char *ip = "127.0.0.1";  
  int port = 3001;         

  int sock;                
  struct sockaddr_in addr; 
  socklen_t addr_size;     
  char buffer[1024];       
  int n;                   

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    perror("[-]Socket error");  
    exit(1);                    
  }
  printf("[+]TCP client socket created.\n");  

  memset(&addr, 0, sizeof(addr));  
  addr.sin_family = AF_INET;       
  addr.sin_port = port;            
  addr.sin_addr.s_addr = inet_addr(ip);

  int r = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
  
  printf("Connected to the server.\n");  

  while(1){
    bzero(buffer, 1024);
    printf("Enter Message to the Client: ");  
    fgets(buffer, 1024, stdin);  
    if (strcmp(buffer, "EXIT\n") == 0)
            break;
    printf("Client: %s\n", buffer);  
    send(sock, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s\n", buffer);  
  }

  close(sock);
  printf("Disconnected from the server.\n");  

  return 0;
}