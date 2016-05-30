#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>

void main()
{ 
	int sock,usock;
	sock = socket(AF_INET, SOCK_STREAM,0);
	int rcvbuf, 
	    debug, 
	    acceptconn, 
	    reusaddr, 
	    keepalive, 
	    oobinline, 
	    sndbuf, 
	    type,  
	    sndtimeo, 
	    rcvtimeo;
	int s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
  
/*
Name: Aakash Shah
SJSU ID: 010767354
Class ID: 64
*/ 

//to get default values of receive buffer using getsockopt()
  
  s1 = sizeof(rcvbuf);
  s2 = sizeof(debug);
  s3 = sizeof(acceptconn);
  s4 = sizeof(reusaddr);
  s5 = sizeof(keepalive);
  s6 = sizeof(oobinline);
  s7 = sizeof(sndbuf);
  s8 = sizeof(type);
  s9 = sizeof(sndtimeo);
  s10 = sizeof(rcvtimeo);
  
  printf("The default vaules of the socket option are:\n");
  
  getsockopt(sock, SOL_SOCKET, SO_RCVBUF, &rcvbuf, &s1);
  printf ("Sock receive buffer size is:%d\n", rcvbuf);

  getsockopt(sock, SOL_SOCKET, SO_DEBUG, &debug, &s2);
  printf ("Sock debug status is:%d\n", debug);

  getsockopt(sock, SOL_SOCKET, SO_ACCEPTCONN, &acceptconn, &s3);
  printf ("Sock accept connection status:%d\n", acceptconn);

  getsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reusaddr, &s4);
  printf ("Sock reuse address status is:%d\n", reusaddr);

  getsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &keepalive, &s5);
  printf ("Sock keep alive status is:%d\n", keepalive);

  getsockopt(sock, SOL_SOCKET, SO_OOBINLINE, &oobinline, &s6);
  printf ("Sock out of band inline status is:%d\n", oobinline);

  getsockopt(sock, SOL_SOCKET, SO_SNDBUF, &sndbuf, &s7);
  printf ("Sock send buffer size is:%d\n", sndbuf);

  getsockopt(sock, SOL_SOCKET, SO_TYPE, &type, &s8);
  printf ("Sock type is:%d\n", type);

  getsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &sndtimeo, &s9);
  printf ("Sock send time out option is:%d\n", sndtimeo);

  getsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &rcvtimeo, &s10);
  printf ("Sock receive time out is:%d\n", rcvtimeo);
}
