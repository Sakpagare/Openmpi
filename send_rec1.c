#include<stdio.h>
#include<mpi.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank == 0){
		char name[] = "sakshi";
		MPI_Send(name,100,MPI_CHAR,1,0,MPI_COMM_WORLD);
		printf("Process 0 send : %s\n",name);
	}else if(rank == 1){
		char name[100];
		MPI_Recv(&name,100,MPI_CHAR,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Process 1 Received : %s\n",name);
	}

	MPI_Finalize();
	return 0;
}
