#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank == 0){
		for(int i =0;i<5;i++){
			MPI_Send(&i,1,MPI_INT,1,0,MPI_COMM_WORLD);
		}
		//printf("\n");
	}else if(rank == 1){
		for(int i = 0;i<5;i++){
			MPI_Recv(&i,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf("Process 1 received:%d\n",i);
		}
	       //printf("\n");
	}


	MPI_Finalize();
       return 0;
}       
