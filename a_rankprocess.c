#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {

    MPI_Init(NULL, NULL);
    
    int size;
    int rank;
    int name_len;
  
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
    printf("This is from process %d of %d\n", rank, size);

    MPI_Finalize();
}

/*
 * How to compile & run:
 * 
 * $ mpicc -o rank a_rankprocess.c
 * 
 * $ mpirun -np 4 ./rank
 * 
 */
