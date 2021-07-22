#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef struct integralArgs
{
	int threadID;
    int threadCount; // total number of threads
	int intervalCount; // total number of intervals
	int intervalStart; // what interval each thread starts at
	int intervalsPerThread; 
	double width;
}integralArgs;

double globalSum; // sum for every thread
pthread_mutex_t mutex; // used to lock access to globalSum

void *decomp(void *); // calculate the integral

int main(int argc, char **argv) 
{
	if (argc != 3) 
    {
		printf("Usage: ./parallel intervals threads\n");
		exit(-1);
	}

	struct timespec start, stop;
	clock_gettime(CLOCK_REALTIME, &start); // track the execution time
	
	integralArgs *args;
	int intervals = atoi(argv[1]);
    int threads = atoi(argv[2]);

	if (intervals < 0) // perform error checking
    {
		printf("Number of intervals must be greater than 0.\n");
		exit(-1);
	}
	if (threads < 0) 
    {
		printf("Number of threads must be greater than 0.\n");
		exit(-1);
	}
	if (threads > intervals) 
    {
		printf("You cannot have more intervals than threads.\n");
		exit(-1);
	}

	double width = (double)1/intervals;
	int remainder = intervals%threads;	// certain threads will get extra intervals
	int status;	// error checking for pthread_create
	int currentInterval = 0;	
	globalSum = 0;
	
	pthread_t threadArray[threads];
	
	for (int i=0; i<threads; i++) 
    {
		args = malloc(sizeof(integralArgs));
		args->threadID = i+1;
		args->intervalCount = intervals;
		args->intervalStart = currentInterval;
		args->intervalsPerThread = intervals/threads;	// intervals per thread
		currentInterval += args->intervalsPerThread;

		if (remainder > 0) // handle the remainder
        {		
			remainder--; // use one less interval to calculate
			args->intervalsPerThread++; // threads will calculate an extra interval
			currentInterval++;
		}

		args->threadCount = threads;
		args->width = width;

		status = pthread_create(&threadArray[i], NULL, decomp, (void*)args); // create pthread
		if (status) 
        {
			printf("Error in creating the threads: %d\n", i+1);
			return -1;
		}
	}
	
	for (int i = 0; i < args->threadCount; i++) 
    {
		pthread_join(threadArray[i], NULL);
	}
	
	double finalCalc = 4*globalSum; // get final answer
	
	clock_gettime(CLOCK_REALTIME, &stop);
	unsigned long long totalSeconds = (long long)(stop.tv_sec - start.tv_sec);
	unsigned long totalNanoseconds = stop.tv_nsec - start.tv_nsec;

	printf("Total execution time: %llu.%.9lu\n", totalSeconds, totalNanoseconds);
	printf("Final calculation: %.12f\n", finalCalc);
	
	free(args);
	return 0;
}


void *decomp(void *argument) 
{
	integralArgs *threadArgs = (integralArgs*)argument;
	double sum = 0;			
	int myInterval = threadArgs->intervalStart; // keep up with what interval you are on
	
	double temp1, temp2;
	temp1 = sqrt(1-pow(myInterval*threadArgs->width, 2)); // use trapezoid theorem to solve the integral
	for (int i=0; i < threadArgs->intervalsPerThread; i++) 
    {
		temp2 = sqrt(1-pow((myInterval+1)*threadArgs->width, 2));
		sum += ((temp1+temp2)/2)*threadArgs->width;
		temp1 = temp2;
		myInterval++;
	}
	
	pthread_mutex_lock(&mutex);		// get access to globalSum
	globalSum += sum;			
	pthread_mutex_unlock(&mutex);	// release exclusive access to globalSum
}