//process 0 sends an array to process 1,which prints the elements 

#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);
	
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);


	if(rank == 0){
		int arr[5] = {1,2,3,4,5};
		MPI_Send(arr,5,MPI_INT,1,0,MPI_COMM_WORLD);
		printf("Process 0 sent array");

	}else if(rank == 1){
		int received[5];
		MPI_Recv(received,5,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Process 1 received array:");
		for(int i = 0;i<5;i++){
			printf("%d ",received[i]);
		}
		printf("\n");
	}

	MPI_Finalize();

	return 0;
}
