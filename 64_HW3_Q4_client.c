/* 
Name: Aakash Shah
SJSU ID: 010767354
Class ID: 64
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>


#define SERVER_NAME "localhost"
#define LINELEN 128

void main(int argc, char *argv[])
{
   int    clientfd=-1, rc, n=0;
   char   buffer[LINELEN+1];
   char   servernode[100];
   char   servport[] = "1212";
   struct in6_addr servaddr;
   struct addrinfo hints, *res=NULL;

   if (argc > 1)
         strcpy(servernode, argv[1]);
   else
         strcpy(servernode, SERVER_NAME);

      memset(&hints, 0x00, sizeof(hints));
      hints.ai_flags    = AI_NUMERICSERV;
      //can be both ipv4 or ipv6 addresses
      hints.ai_family   = AF_UNSPEC;    
      hints.ai_socktype = SOCK_STREAM;
      
      //To convert the text form of the address to binary
      rc = inet_pton(AF_INET, servernode, &servaddr);
      if (rc == 1)    /* valid IPv4 text address? */
      {
         hints.ai_family = AF_INET;
         hints.ai_flags |= AI_NUMERICHOST;
      }
      else
      {
         rc = inet_pton(AF_INET6, servernode, &servaddr);
         if (rc == 1) /* valid IPv6 text address? */
         {

            hints.ai_family = AF_INET6;
            hints.ai_flags |= AI_NUMERICHOST;
         }
      }
      
      //getaddrinfo() combines the getservbyname() and gethostbyname() functionalities into 1 function
      //getaddrinfo() is reentrant and allows programs to eliminate IPv4-versus-IPv6 dependencies
      
      rc = getaddrinfo(servernode, servport, &hints, &res);
      if (rc != 0)
      {
         printf("Host not found:%s\n", gai_strerror(rc));
         if (rc == EAI_SYSTEM)         
            printf("getaddrinfo() failed");
         exit(0);
      }

      
      clientfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
      if (clientfd < 0)
      {
         printf("socket() failed");
         exit(0);
      }
          rc = connect(clientfd, res->ai_addr, res->ai_addrlen);
      if (rc < 0)
      {
        
         printf("connect() failed");
         exit(0);
      }

	printf("\nConnection established\nTime:");
		
		
		while((n=recv(clientfd, buffer, LINELEN, 0))>0)
		{
			buffer[n]='\0';
			(void)fputs(buffer, stdout);
			n=0;	
		}

      close(clientfd);
   
   if (res != NULL)
      freeaddrinfo(res);
}
