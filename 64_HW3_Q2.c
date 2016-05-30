/*
Name: Aakash Shah
SJSU ID: 010767354
Class ID: 64
/*

/* Code with Race Condition problem solved using semaphore */

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define SIZE 4
#define ITEMS 5
#define THREADS 2

typedef struct {
	char buf[SIZE];
	int occupied;
	int in,out;	

} buffer_t;

buffer_t buffer;

void * thread1(void *);
void * thread2(void *);

static sem_t sema;


pthread_t tid[THREADS];

int main( int argc, char *argv[] )
{
	int i;
	
	//Initialized semaphore
	sem_init(&sema, 0, 2);

	pthread_create(&tid[1], NULL, thread2, NULL);
	pthread_create(&tid[0], NULL, thread1, NULL);

	for ( i = 0; i < THREADS; i++)
		pthread_join(tid[i], NULL);

	printf("\nNumber of threads terminated:%d\n", i);
	
	//Destroying the semaphore	
	sem_destroy(&sema);
}

void * thread1(void * parm)
{
	char item[ITEMS]="AKASH";
	int i;

	printf("Thread1 is started\n");

	for(i=0;i<ITEMS;i++)
	{
		if (item[i] == '\0')
		break;

		//Waiting of semaphore and decreasing the value by 1
		sem_wait(&sema);

		if (buffer.occupied >= SIZE)
			printf("Thread1 waiting\n");
	
		while (buffer.occupied >= SIZE)

		printf("Thread1 executing\n");
		buffer.buf[buffer.in++] = item[i];
		buffer.in %= SIZE;
		buffer.occupied++;

		
		//Posting of the semaphore and increasing the value by 1
		sem_post(&sema);
	}
	printf("Thread1 exiting\n");
	pthread_exit(0);
}

void * thread2(void * parm)
{
	char item;
	int i;

	printf("Thread2 is started\n");

	for(i=0;i<ITEMS;i++)
	{

		//Waiting of semaphore and decreasing the value by 1
		sem_wait(&sema);

		if (buffer.occupied <= 0)
			printf("Thread2 waiting\n");

		while(buffer.occupied <= 0)
			printf("Thread2 executing\n");
		
		item = buffer.buf[buffer.out++];
		printf("%c\n",item);
		buffer.out %= SIZE;
		buffer.occupied--;
		
		//unlock the semaphore and increases the value by 1
		sem_post(&sema);
	}
	printf("Thread2 exiting\n");
	pthread_exit(0);
}
