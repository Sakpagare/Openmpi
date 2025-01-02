#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);


	int send_data = rank;
	int recv_data[size];

	MPI_Gather(&send_dat,1,MPI_INT,recv_data,1,MPI_INT,0,MPI_COMM_WORLD);

	if(rank == 0){
		printf("Gathered data at root process: ");
		for(int i = 0;i<size;i++){
			printf("%d ",recv_data[i]);
		}
		printf("\n");
	}

	MPI_Finalize();

	return 0;
}
