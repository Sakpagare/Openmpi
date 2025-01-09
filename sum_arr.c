// Process 0 send an array to process 1.process 1 calculates the sum of the array and sends the result back to process 0.

#include<stdio.h>
#include<mpi.h>


int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
        int arr[10];
	if(rank == 0){
	     for(int i = 0;i<10;i++){
		     arr[i] = i + 1;
	     }
	     MPI_Send(arr,10,MPI_INT,1,0,MPI_COMM_WORLD);
	     printf("the process 0 : element are send to process 1 !\n");
             int sum;
	     MPI_Recv(&sum,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
	     printf("the sum is received form process 1 : %d\n",sum);
	}else if(rank == 1){
		MPI_Recv(arr,10,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		int sum = 0;
		for(int i = 0;i<10;i++){
			sum += arr[i];
		}
		MPI_Send(&sum,1,MPI_INT,0,0,MPI_COMM_WORLD);
		printf("the sum is sent to process 0\n");
	}

	MPI_Finalize();

	return 0;
}
