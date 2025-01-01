#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank % 2 == 0){
		printf("Hello from process : %d and rank : %d\n",size,rank);
	}

	MPI_Finalize();
	return 0;
}
