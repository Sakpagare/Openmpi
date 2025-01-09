// write a program where process 0 sends an array of integers({10,20,30,40,50}) to process 1. Process 1 should receive that array and print each element.
#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;

	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);


	int N[100];
	if(rank == 0){
		for(int i = 0;i<100;i++){
			N[i] = i + 1;
		}
		for(int i=0;i<100;i++){
			printf("process 0 sending value : %d\n",N[i]);
		}

		MPI_Send(N,100,MPI_INT,1,0,MPI_COMM_WORLD);
		printf("process 0 send \n");
	
		}else if(rank == 1){
			MPI_Recv(N,100,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf("process 1 receive :\n");
			for(int i = 0;i<100;i++){
				printf("%d ",N[i]);
			}
			printf("\n");	
		}
	MPI_Finalize();
	return 0;
}
