#include<stdio.h>
#include<mpi.h>
#include<string.h>

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	int a;
	float b;
	char name[20];

	if(rank == 0){
		a = 10;
		b = 4.5f;
		strcpy(name,"sakshi");

		MPI_Send(&a,1,MPI_INT,1,0,MPI_COMM_WORLD);
		MPI_Send(&b,1,MPI_FLOAT,1,0,MPI_COMM_WORLD);
		MPI_Send(name,20,MPI_CHAR,1,0,MPI_COMM_WORLD);
	}else if(rank == 1){

		MPI_Recv(&a,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		MPI_Recv(&b,1,MPI_FLOAT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		MPI_Recv(name,20,MPI_CHAR,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("process 1 receive : %d\n",a);
		printf("process 1 receive : %f\n",b);
		printf("process 1 receive : %s\n",name);

	}

	MPI_Finalize();
	return 0;
}
