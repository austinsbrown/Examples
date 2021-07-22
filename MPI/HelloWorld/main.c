#include <stdio.h>
#include <mpi.h>

int main(void)
{
    MPI_Init(NULL, NULL); // intialize mpi environment

    int worldSize;
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize); // get number of processes

    int worldRank;
    MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);

    char processorName[MPI_MAX_PROCESSOR_NAME]; // get name of processor
    int nameLen;
    MPI_Get_processor_name(processorName, &nameLen);

    printf("Hello World from processor %s, rank %d, out of %d\n",
    processorName, worldRank, worldSize);

    MPI_Finalize();
    return 0;
}