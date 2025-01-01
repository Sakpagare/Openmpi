// The following MPI program initializes an array of size N = 1000 and divides it among multiple processes for initialization and printing.Answer the questions based on the code below.
#include<stdio.h>
#include<mpi.h>
#define N 100

int main(int argc,char** argv){
	int size,rank;
	int a[N];
	MPI_Init(&argc,&argv);

	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	int chunksize = N / size;
	int start = rank * chunksize;
	int end = start + chunksize;

	if(rank == size - 1){
		end = N;
	}
	for(int i =start;i<end;i++){
		a[i] = i + 1;
	}

	for(int i =start;i<end;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	MPI_Finalize();

	return 0;
}
