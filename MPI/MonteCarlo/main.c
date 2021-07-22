#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

#define SEED 35791246
const long int INTERVALS = 10000000;

int main()
{
    int id, nodeNum;
    int i, count = 0;
    double x, y; // holds a random coordinate
    double z; // used to check if corrdinates are in unit circle

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &nodeNum);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    
    int recieved[nodeNum];
    long int* interv = (long int*)malloc(INTERVALS*sizeof(long int));

    srand(SEED+id); // each node gets a different seed value

    if(id != 0)
    {
        for(i=0; i<INTERVALS; ++i)
        {
            x = ((double)rand())/RAND_MAX;
            y = ((double)rand())/RAND_MAX;
            z = sqrt(x*x+y*y);

            if(z<=1) // check to see if z is in the unit circle
                count++;
        }

        for(i=0; i<nodeNum; ++i)
        {
            MPI_Send(&count, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
            MPI_Send(&INTERVALS, 1, MPI_LONG, 0, 2, MPI_COMM_WORLD);
        }
    }
    else if(id == 0)
    {
        for(i=0; i<nodeNum; ++i)
        {
            MPI_Recv
            (
                &recieved[i], 
                nodeNum, 
                MPI_INT, 
                MPI_ANY_SOURCE, 
                1, 
                MPI_COMM_WORLD, 
                MPI_STATUS_IGNORE
            );

            MPI_Recv
            (
                &interv[i],
                nodeNum,
                MPI_LONG,
                MPI_ANY_SOURCE,
                2,
                MPI_COMM_WORLD,
                MPI_STATUS_IGNORE
            );
        }
    }

    if(id == 0)
    {
        int finalCount = 0;
        long finalInterval = 0;
        for(i=0; i<nodeNum; ++i)
        {
            finalCount += recieved[i];
            finalInterval += interv[i];
        }

        double result = ((double)finalCount/(double)finalInterval)*4.0;
        printf("Result %f\n", result);
    }
    MPI_Finalize();
    free(interv);
    return 0;
}