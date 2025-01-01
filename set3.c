//create an mpi program where process 0 sends a string "Hello from process 0" to process 1. process 1 should receive and print the string
#include<stdio.h>
#include<mpi.h>
#include<string.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	char name[100];
	
	if(rank ==0){
		strcpy(name,"Hello from process 0");
		MPI_Send(name,100,MPI_CHAR,1,0,MPI_COMM_WORLD);
		printf("process 0 send : %s\n",name);
	}else if(rank ==1){
		MPI_Recv(name,100,MPI_CHAR,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("process 1 receive : %s\n",name);
	}

	MPI_Finalize();

	return 0;
}
