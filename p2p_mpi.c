#include<stdio.h>
#include<mpi.h>

int main(){
	int rank,size;
	int val;

	MPI_Init(NULL,NULL);

	MPI_Comm_size(MPI_COMM_WORLD,&size);

	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank == 0){
		val = 100;
		printf("\n rank : %d \t val = %d",rank,val);
		for(int i = 1;i<size;i++){
			MPI_Send(&val,1,MPI_INT,i,0,MPI_COMM_WORLD);
		}
		printf("\n rank : %d \t Data sent.\n",rank);
	}else{
		if(rank == size - 1){
			printf("i left\n");
		}else{
			val = 200;
			MPI_Recv(&val,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf("\n rank: %d \t Data received. \n",rank);
			printf("\n rank: %d \t val = %d\n",rank,val);
		}
	}
	MPI_Finalize();

	return 0;
}
