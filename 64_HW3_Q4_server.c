/* 
Name: Aakash Shah
SJSU ID: 010767354
Class ID: 64
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<string.h>
#include <stdlib.h>
#include<unistd.h>

#define SERVER_PORT     1212
#define BUFFER_LENGTH    250
#define FALSE              0

void TCPdaytimed(int fd);

void main()
{
   int servfd=-1, clientfd=-1;
   int rc, on=1, rcdsize=BUFFER_LENGTH;
   
   struct sockaddr_in6 servaddr={0}, clientaddr={0};
   int addrlen=sizeof(clientaddr);
   char str[INET6_ADDRSTRLEN];

   
     if ((servfd = socket(AF_INET6, SOCK_STREAM, 0)) < 0)
      {
         perror("socket() failed");
         exit(0);
      }

     
      if (setsockopt(servfd, SOL_SOCKET, SO_REUSEADDR,(char *)&on,sizeof(on)) < 0)
      {
         perror("setsockopt(SO_REUSEADDR) failed");
         exit(0);
      }

      servaddr.sin6_family = AF_INET6;
      servaddr.sin6_port   = htons(SERVER_PORT);
      
      servaddr.sin6_addr   = in6addr_any;
     

      if (bind(servfd,
               (struct sockaddr *)&servaddr,
               sizeof(servaddr)) < 0)
      {
         perror("bind() failed");
         exit(0);
      }

    
      if (listen(servfd, 10) < 0)
      {
         perror("listen() failed");
         exit(0);
      }
    do
    {
      printf("Ready for client connect().\n");

     
      if ((clientfd = accept(servfd, NULL, NULL)) < 0)
      {
         perror("accept() failed");
         break;
      }
      else
      {
         
         getpeername(clientfd, (struct sockaddr *)&clientaddr, &addrlen);
         if(inet_ntop(AF_INET6, &clientaddr.sin6_addr, str, sizeof(str))) 
         {
           printf("\n \t");
         }

TCPdaytimed(clientfd);
      }
      
   } while (1);

   if (servfd != -1)
      close(servfd);   
}

void TCPdaytimed(int fd)
{	
	char *pts;
	time_t now;
	char *ctime();
	(void)time(&now);
	pts=ctime(&now);
	(void)write(fd, pts, strlen(pts));
close(fd);
}
