/*
Name: Aakash Shah
SJSU ID: 010767354
Class ID: 64
*/

/* Code to demonstrate setsockopt() */

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>

void main()
{ 
  int tcpsock,udpsock;
  tcpsock = socket(AF_INET, SOCK_STREAM,0);
  udpsock = socket(AF_INET, SOCK_DGRAM, 0);
  int tcprcvbufsize, udprcvbufsize;
  int size;

  // using getsockopt to get default value of receive buffer for tcp and udp
  size = sizeof(tcprcvbufsize);
  getsockopt(tcpsock, SOL_SOCKET, SO_RCVBUF, &tcprcvbufsize, &size);
  printf ("TCP socket receive buffer size is:%d\n", tcprcvbufsize);

  size = sizeof(udprcvbufsize);
  getsockopt(udpsock, SOL_SOCKET, SO_RCVBUF, &udprcvbufsize, &size);  
  printf ("UDP socket receive buffer size is:%d\n", udprcvbufsize);

  //setsockopt() to change tcp receive buffer and udp receive buffer
  tcprcvbufsize = 80000;
  udprcvbufsize = 200000;

  size = sizeof(tcprcvbufsize);
  setsockopt(tcpsock, SOL_SOCKET, SO_RCVBUF, &tcprcvbufsize, size);
  printf ("TCP socket receive buffer size after change:%d\n", tcprcvbufsize);

  size = sizeof(udprcvbufsize);
  setsockopt(udpsock, SOL_SOCKET, SO_RCVBUF, &udprcvbufsize, size);  
  printf ("UDP socket receive buffer size after change:%d\n", udprcvbufsize);
}
