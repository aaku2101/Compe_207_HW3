/*
Name: Aakash Shah
SJSU ID: 010767354
Class ID: 64
/*

/* Code with Race Condition problem solved using mutex and condition variables */

#include <pthread.h>
#include <stdio.h>

#define SIZE 4
#define ITEMS 5
#define THREADS 2

typedef struct {
	char buf[SIZE];
	int occupied;
	int in,out;

	pthread_mutex_t mutex;  //Used mutex
	pthread_cond_t m;  //Used Conditional variable 
	pthread_cond_t l;  //Used Conditional variable
	} buffer_t;

buffer_t buffer;

void * thread1(void *);
void * thread2(void *);


pthread_t tid[THREADS];

int main( int argc, char *argv[] )
{
	int i;
	
	//Initialized Condition variable and Mutex
	pthread_cond_init(&(buffer.m), NULL);
	pthread_cond_init(&(buffer.l), NULL);

	pthread_create(&tid[1], NULL, thread2, NULL);
	pthread_create(&tid[0], NULL, thread1, NULL);

	for ( i = 0; i < THREADS; i++)
		pthread_join(tid[i], NULL);

	printf("\nNumber of threads terminated:%d\n", i);
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

		//Lock the mutex
		pthread_mutex_lock(&(buffer.mutex));

		if (buffer.occupied >= SIZE)
			printf("Thread1 waiting\n");
	
		while (buffer.occupied >= SIZE)

			//Condition variable wait
			pthread_cond_wait(&(buffer.l), &(buffer.mutex) );
		
		printf("Thread1 executing\n");
		buffer.buf[buffer.in++] = item[i];
		buffer.in %= SIZE;
		buffer.occupied++;

		//Condition variable signal
		pthread_cond_signal(&(buffer.m));

		//Unlock the mutex
		pthread_mutex_unlock(&(buffer.mutex));
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

		//Lock the mutex
		pthread_mutex_lock(&(buffer.mutex) );

		if (buffer.occupied <= 0)
			printf("Thread2 waiting\n");

		while(buffer.occupied <= 0)

		//Condition variable wait
		pthread_cond_wait(&(buffer.m), &(buffer.mutex) );

		printf("Thread2 executing\n");
		item = buffer.buf[buffer.out++];
		printf("%c\n",item);
		buffer.out %= SIZE;
		buffer.occupied--;
		
		//Condition variable signal
		pthread_cond_signal(&(buffer.l));

		//Unlock the mutex
		pthread_mutex_unlock(&(buffer.mutex));
	}
	printf("Thread2 exiting\n");
	pthread_exit(0);
}
