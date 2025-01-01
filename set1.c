//write a program that uses MPI to send an integer from process 0 to process 1. Process 0 should send the integer value 42, and Process 1 should receive it and print the value.

#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank == 0){
		int num = 42;
		MPI_Send(&num,1,MPI_INT,1,0,MPI_COMM_WORLD);
		printf("process 0 send : %d\n",num);
	}else if(rank == 1){
		int num;
		MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Process 1 receive : %d\n",num);
	}

	MPI_Finalize();

	return 0;
}
