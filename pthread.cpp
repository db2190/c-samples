/*
Pthread librari API usage program.
usage: g++ pthread.cpp -lpthread
*/

#include <stdlib.h>
#include <pthread.h>

#include <iostream>
using namespace std;

#define NUM_THREADS 50

void* PrintHello(void* threadId)
{
	long tid;

	tid = (long)threadId;
	cout << "Thread id is : " << tid << endl;
	pthread_exit(NULL);

}

int main()
{
	pthread_t threads[NUM_THREADS];
	int rc;
	int i;

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

	pthread_exit(NULL);

	return 0;
}
