#include<stdio.h>
#include<mpi.h>

int main(int argc,char **argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	printf("Hello from process %d\n",rank);

	MPI_Finalize();

	return 0;
}
