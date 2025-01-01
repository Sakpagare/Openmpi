#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);


	int N[20];
	if(rank ==0){
		for(int i =0;i<20;i++){
			N[i] = i + 1;
		}

		MPI_Send(N,20,MPI_INT,1,0,MPI_COMM_WORLD);
		printf("process 0 sent array!");

	}else if(rank == 1){
		int receive[20];
		MPI_Recv(receive,20,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		for(int i=0;i<20;i++){
			printf("%d ",receive[i]);
		}
		printf("\n");
	}

	MPI_Finalize();

	return 0;
}
