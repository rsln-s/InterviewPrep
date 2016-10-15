#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void print(int* myarr){
	for (int i = 0; i < 10; i++)
		printf("%d ", myarr[i]);
	printf("\n");
}

void populate(int* myarr){
	for (int i = 0; i < 9; i++)
		myarr[i] = i;
}

int main(){
    MPI_Init(NULL, NULL);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int* arr = (int*) malloc(10*sizeof(int));

	if (world_rank == 0)
		populate(arr);
	
	MPI_Bcast(arr, 10, MPI_INT, 0, MPI_COMM_WORLD);
	if (world_rank == 1){
		printf("Rank :%d , array:", world_rank);
		print(arr);
	}
	MPI_Finalize();
	return 0;
}
