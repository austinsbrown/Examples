#include <mpi.h>
#include <stdio.h>

int main(void)
{
    MPI_Init(NULL, NULL);

    int worldRank;
    int worldSize;
    MPI_Comm_rank(MPI_COMM_WORLD, &worldRank);
    MPI_Comm_size(MPI_COMM_WORLD, &worldSize);

    if(worldSize < 2)
    {
        printf("Must have a worldsize greater than 1\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int i;
    if(worldRank == 0)
    {
        i = -1;
        MPI_Send
        (
            &i, // data to send
            1, // count
            MPI_INT, // data type
            1, // dstination
            0, // tag
            MPI_COMM_WORLD // communicator
        );
    }

    else if(worldRank == 1)
    {
        MPI_Recv
        (
            &i, // data 
            1, // count
            MPI_INT, // datatype
            0, // source
            0, // tag
            MPI_COMM_WORLD, // communicator
            MPI_STATUS_IGNORE // status
        );

        printf("Process 1 recieved\n");
    }
    MPI_Finalize();
    return 0;
}