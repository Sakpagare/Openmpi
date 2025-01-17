#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define N 15

int
main (int argc, char **argv)
{
  MPI_Init (&argc, &argv);

  int rank, size;
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);


  int data[N][N];
  const int count = 3;
  const int blocklength = 1;
  const int stride = 6;

  MPI_Datatype vector_type;

  MPI_Type_vector (count, blocklength, stride, MPI_INT, &vector_type);
  MPI_Type_commit (&vector_type);

  if (size < 2)
    {
      fprintf (stderr,
	       "World size must be greater than 1 for this example\n");
      MPI_Abort (MPI_COMM_WORLD, 1);
    }
  if (rank == 0)
    {
      int tmp = 1;
      for (int i = 0; i < N; i++)
	{
	  for (int j = 0; j < N; j++)
	    {
	      data[i][j] = tmp;
	      tmp++;
	    }
	}
      for (int i = 1; i < N; i++)
	{
	  MPI_Send (data, 1, vector_type, i, 0, MPI_COMM_WORLD);
	}

      printf ("Process 0 sent data:\n ");
      for (int i = 0; i < N; i++)
	{
	  printf ("%d ", data[i]);
	}
      printf ("\n");
    }

for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      {
	data[i][j] = 0;
      }

  }


MPI_Recv (data, N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);


printf ("Process 1 received data:\n ");



printf ("\n");

MPI_Type_free (&vector_type);
MPI_Finalize ();
return 0;
}
