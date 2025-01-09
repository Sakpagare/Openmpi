// Process 0 sends two mesages to Process 1 with different tags. Process 1 receives and distinguishes them.

#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank == 0){
		int data1 = 100,data2 = 200;
		MPI_Send(&data1,1,MPI_INT,1,1,MPI_COMM_WORLD);
		MPI_Send(&data2,1,MPI_INT,1,2,MPI_COMM_WORLD);

		printf("Process 0 sent data: %d and %d\n",data1,data2);
	}else if(rank == 1){
		int val,val1;
		MPI_Recv(&val,1,MPI_INT,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		MPI_Recv(&val1,1,MPI_INT,0,2,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Process 1 received data: %d and %d\n",val,val1);
	}

	MPI_Finalize();

	return 0;
}
