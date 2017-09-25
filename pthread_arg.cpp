/*
Pthread librari API usage program.
usage: g++ pthread.cpp -lpthread
*/

#include <stdio.h>	//sprintf
#include <stdlib.h>
#include <pthread.h>

#include <iostream>
using namespace std;

#define NUM_THREADS 50

struct thread_data
{
	int thread_id;
	char *message;
};

 
void* PrintHello(void* threadArg)
{
	struct thread_data *my_data;
	my_data = (struct thread_data *) threadArg;

	cout << "Thread ID : "<< my_data->thread_id << endl;
	cout << "Thread Message : "<< my_data->message << endl;
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	int i, rc;
	struct thread_data td[NUM_THREADS];
	char tempStr[20];

	for (i = 0; i < NUM_THREADS; i++)
	{
		td[i].thread_id = i;
		//snprintf(tempStr, 37, "This is message from thread id: %d", i);
		//td[i].message = tempStr;
		//strncpy(td[i].message, tempStr);
		td[i].message = "This is message";
		cout << "Main: Creating thread" << i << endl;
		rc= pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);
		//rc= pthread_create(&threads[i], NULL, PrintHello, i);
		if (rc)
		{
			cout << "Error : Unable to create thread. " << rc << endl;
			exit (-1);
		}
	}

	pthread_exit(NULL);

	return 0;
}
