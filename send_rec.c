#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank == 0){
		int message = 10;
		MPI_Send(&message,1,MPI_INT,1,0,MPI_COMM_WORLD);
		printf("process 0 sent : %d\n",message);
	}else if(rank == 1){
		int message;
		MPI_Recv(&message,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Process 1 received : %d\n",message);
	}

	MPI_Finalize();
	return 0;
}
