//write a program where process 0 sends a message to process 1. process 1 receives the message,then sends a reply message back to process 0.Both processes should print the message they received.


#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
        int n;
	if(rank == 0){
		n = 4;
		MPI_Send(&n,1,MPI_INT,1,0,MPI_COMM_WORLD);
		printf("Process 0 send : %d\n",n);

		MPI_Recv(&n,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Process 0 Receive : %d\n",n);

	}else if(rank == 1){
		MPI_Recv(&n,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Process 1 receive : %d\n",n);
                n = 6;
		MPI_Send(&n,1,MPI_INT,0,0,MPI_COMM_WORLD);
		printf("Process 1 send : %d\n",n);
	}

	MPI_Finalize();

	return 0;
}

