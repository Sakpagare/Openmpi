#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv); //Initialize MPI
	

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	printf("Hello from process %d out of %d process \n",rank,size);


	MPI_Finalize();


	return 0;
}
