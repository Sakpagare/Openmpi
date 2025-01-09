#include<stdio.h>
#include<mpi.h>
#define N 100

int main(int argc,char** argv){
	MPI_Init(&argc,&argv);

	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);


	int chunksize = N / size;
	int arr[N];
	int sub_arr[chunksize];


	if(rank == 0){
		for(int i=0;i<N;i++){
			arr[i] = i + 1;
		}
	}
	MPI_Scatter(arr,chunksize,MPI_INT,sub_arr,chunksize,MPI_INT,0,MPI_COMM_WORLD);

	int local_sum = 0;
	for(int i = 0;i<chunksize;i++){
		local_sum += sub_arr[i];
	}

	int final_sum = 0;
	MPI_Reduce(&local_sum,&final_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

	if(rank == 0) {
		printf("The total sum of array elements is %d\n",final_sum);
	}


	MPI_Finalize();
	return 0;
}

