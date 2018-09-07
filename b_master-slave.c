#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	MPI_Init(NULL, NULL);
	
    int rank;
    int procs;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	MPI_Comm_size(MPI_COMM_WORLD, &procs);
	
	if(procs != 2){
		printf("Run this program with exactly two arguments\n");
		MPI_Abort(MPI_COMM_WORLD, 1);
	}
	
	int num;

	if(rank == 0){
		printf("Enter an interger: ");
		scanf("%d", &num);
		MPI_Send(&num, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}
	
	if(rank == 1){
		MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Received %d from process another process\n", num);
	}
	
	MPI_Finalize();
}
