// write an MPI program wher process 0 sends numbers from 1 to 5 to process.process 1 should receive each number and print it.use a loop to send and receive the numbers


#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);


	int arr[5];
	if(rank == 0){
		for(int i = 0;i<5;i++){
			arr[i] = i  + 1;
		}

		for(int i =0;i<5;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");

		MPI_Send(arr,5,MPI_INT,1,0,MPI_COMM_WORLD);
	}else if(rank == 1){
		MPI_Recv(arr,5,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		for(int i=0;i<5;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	}

	MPI_Finalize();

	return 0;
}
		
