#include<stdio.h>
#include<mpi.h>

int main (int argc, char** argv){

MPI_Init(&argc , &argv );

int rank ;
MPI_Comm_rank ( MPI_COMM_WORLD,&rank );

int data ;
if (rank == 0){
data = 100;
}

MPI_Bcast(&data,1,MPI_INT,0,MPI_COMM_WORLD);
printf("Process %d received data %d\n",rank,data);


MPI_Finalize(); 

return 0;
}



