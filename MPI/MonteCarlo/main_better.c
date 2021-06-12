#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>

#define SEED 35791246
const long int INTERVALS = 10000000;

int main()
{
    int id, nodeNum;
    int i, count = 0;
    double x, y; // holds a random coordinate
    double z; // used to check if corrdinates are in unit circle
    int reducedCount;
    int reducedInterval;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &nodeNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    for(i=0; i<INTERVALS; ++i)
    {
        srand48(time(NULL)+id);
        x = ((double)rand())/RAND_MAX;
        y = ((double)rand())/RAND_MAX;
        z = sqrt(x*x+y*y);

        if(z<=1) // check to see if z is in the unit circle
            count++;
    }

    MPI_Reduce
    (
        &count,
        &reducedCount,
        1,
        MPI_INT,
        MPI_SUM,
        0,
        MPI_COMM_WORLD
    );
    MPI_Reduce
    (
        &INTERVALS,
        &reducedInterval,
        1,
        MPI_INT,
        MPI_SUM,
        0,
        MPI_COMM_WORLD
    );

    if(id==0)
    {
        double result = ((double)reducedCount/(double)reducedInterval)*4.0;
        printf("Result: %f\n", result);
    }

    MPI_Finalize();
    return 0;
}