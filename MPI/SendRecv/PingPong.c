#include <mpi.h>
#include <stdio.h>

const int PING_PONG_LIMIT = 10;

int main()
{
    MPI_Init(NULL, NULL);

    int worldRank, worldSize;
    MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);

    if(worldSize != 2) // assume 2 processes
    {
        printf("World Size has to be 2\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int pingPongCount = 0;
    int partnerRank = (worldRank+1) % 2;
    while (pingPongCount < PING_PONG_LIMIT)
    {
        if(worldRank == pingPongCount%2)
        {
            pingPongCount++;
            MPI_Send(&pingPongCount, 1, MPI_INT, partnerRank, 0, MPI_COMM_WORLD);
            printf("%d sent and incremented count %d to %d.\n", worldRank, pingPongCount, partnerRank);
        }

        else
        {
            MPI_Recv(&pingPongCount, 1, MPI_INT, partnerRank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("%d received ping_pong_count %d from %d\n", worldRank, pingPongCount, partnerRank);
        }
    }
    

    MPI_Finalize();
    return 0;
}