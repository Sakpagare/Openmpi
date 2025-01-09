#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank == 0){
		printf("I am the master process.\n");
	}else{
		printf("I am a worker process,rank: %d\n",rank);
	}

	MPI_Finalize();

	return 0;
}
