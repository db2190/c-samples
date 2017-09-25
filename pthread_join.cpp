/*
Pthread librari API usage program.
usage: g++ pthread.cpp -lpthread
*/

#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include <iostream>
using namespace std;

#define NUM_THREADS 50

void* PrintHello(void* threadId)
{
	long tid;

	tid = (long)threadId;
	sleep(1);
	cout << "Sleeping in thread" << endl;
	cout << "Thread id : " << tid << " exiting..." << endl;
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	int rc;
	int i;
	void* status;

	// Initialize and set pthread joinable.
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0; i < NUM_THREADS; i++)
	{
		cout << "Main: Creating thread" << i << endl;
		rc= pthread_create(&threads[i], NULL, PrintHello, (void *)i);
		//rc= pthread_create(&threads[i], NULL, PrintHello, i);
		if (rc)
		{
			cout << "Error : Unable to create thread. " << rc << endl;
			exit (-1);
		}
	}

	// Free attribute and wait for the other threads.
	pthread_attr_destroy(&attr);
	for (i = 0; i < NUM_THREADS; i++)
	{
		rc = pthread_join(threads[i], &status);
		if (rc)
		{
			cout << "Error: joining the threadi " << rc << endl;
			exit(-1);
		}

		cout << "Main: completed thread id " << i << endl;
		cout << "Exiting with status " << status << endl;
	}

	cout << "Main: program exiting" << endl;	
	pthread_exit(NULL);

	return 0;
}
