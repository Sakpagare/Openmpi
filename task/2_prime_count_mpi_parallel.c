#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpi.h>
#include<time.h>
#include<sys/time.h>

#define N 100000

int
main ()
{
  int i, j, rank, size;
  int count, flag, totalcount;
  double exe_time;
  struct timeval stop_time, start_time;
  MPI_Init (NULL, NULL);

  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);

 count =0 ;
 int chunksize = N / size;
  int start = rank * chunksize;
  if (rank == 0)
    {
      start = 3;
  count = 1;			// 2 is prime. Our loop starts from 3
    }
  int end = start + chunksize;
  if (rank == size - 1)
    {
      end = N;
    }

  if (rank == 0)
    {
      gettimeofday (&start_time, NULL);
    }

  for (i = start; i < end; i++)
    {
      flag = 0;
      for (j = 2; j < i; j++)
	{
	  if ((i % j) == 0)
	    {
	      flag = 1;
	      break;
	    }
	}
      if (flag == 0)
	{
	  count++;
	}
    }

  MPI_Reduce (&count, &totalcount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);



  if (rank == 0)
    {
      gettimeofday (&stop_time, NULL);

      exe_time =
	(stop_time.tv_sec + (stop_time.tv_usec / 1000000.0)) -
	(start_time.tv_sec + (start_time.tv_usec / 1000000.0));

      printf
	("\n Number of prime numbers = %d \n Execution time is = %lf seconds\n",
	 totalcount, exe_time);
    }


MPI_Finalize();

return 0 ;




}
