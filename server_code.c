#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h> 

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
  
// Function to handle arithmetic calculations 
void func(int connfd) 
{ 
    char buff[MAX]; 
    for (;;) { 
        bzero(buff, MAX); 
  
        // Read the expression from client 
        read(connfd, buff, sizeof(buff)); 
        
        // Check for exit condition
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Client requested exit. Server Exit...\n"); 
            break; 
        } 

        printf("Received expression from client: %s", buff); 

        double num1, num2, result = 0; 
        char op; 
        int valid = 1; 

        // Parse format: number operator number (e.g., 10 + 5)
        if (sscanf(buff, "%lf %c %lf", &num1, &op, &num2) == 3) { 
            switch (op) { 
                case '+': result = num1 + num2; break; 
                case '-': result = num1 - num2; break; 
                case '*': result = num1 * num2; break; 
                case '/': 
                    if (num2 != 0) 
                        result = num1 / num2; 
                    else 
                        valid = 0; // Division by zero error
                    break; 
                default: 
                    valid = 0; // Invalid operator
                    break; 
            } 
        } else { 
            valid = 0; // Invalid format
        } 

        bzero(buff, MAX); 
        if (valid) { 
            snprintf(buff, MAX, "Result: %.2f\n", result); 
        } else { 
            snprintf(buff, MAX, "Invalid expression or division by zero!\n"); 
        } 

        // Send the result back to client 
        write(connfd, buff, sizeof(buff)); 
    } 
} 
  
int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    
    bzero(&servaddr, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    
    len = sizeof(cli); 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server accept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server accepted the client..\n"); 
  
    func(connfd); 
    close(sockfd); 
}