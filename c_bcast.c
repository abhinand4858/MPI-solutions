#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
        
    int rank;
    int buf=0;

    int root=0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == root) {
        buf = 777; //writing 777 to buffer
    }

    printf("Process %d: Buffer not updated - %d\n", rank, buf);

    MPI_Bcast(&buf, 1, MPI_INT, root, MPI_COMM_WORLD);

    printf("Process %d: Updated buffer - %d\n", rank, buf);

    MPI_Finalize();
    return 0;
}
