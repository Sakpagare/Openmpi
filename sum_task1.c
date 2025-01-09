#include <stdio.h>
#include <mpi.h>

int main() {
    int size, rank;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    const int n = 1000;           
    int chunksize = n / size;     
    int start = rank * chunksize; 
    //int end = (rank == size - 1) ? n : start + chunksize; 
    int end =0;
    for(int i =0;i<size;i++){
	    if(rank == i){
		    if(i == size - 1){
			    end = n;
		    }else{
			    end = start + chunksize;
		    }
	    }
    }


    int localsum = 0;
    for (int i = start; i < end; i++) {
        localsum += (i + 1); 
    }

    
    int totalsum = 0;
    MPI_Reduce(&localsum, &totalsum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    
    if (rank == 0) {
        printf("Total sum = %d\n", totalsum);
    }

    MPI_Finalize();
    return 0;
}

