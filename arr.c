#include<stdio.h>
#include<mpi.h>
#define N 100


int main(){
	MPI_Init(NULL,NULL);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	int arr[N];

	if(rank == 0){
		for(int i=0;i<N;i++){
			arr[i] = i + 1;
		}
		MPI_Send(arr,N,MPI_INT,1,0,MPI_COMM_WORLD);
	}else if(rank == 1){
		MPI_Recv(arr,N,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		for(int i = 0;i<N;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	MPI_Finalize();
	return 0;
}
