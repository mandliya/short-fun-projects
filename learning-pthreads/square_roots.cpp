#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>


void * compute_square_root( void * arg )
{
  double * roots = (double *)malloc(100 * sizeof(double));
  int i = 0;
  for ( i = 0; i < 100; ++i ) {
    roots[i] = sqrt(i);
  }
  return roots;
}

int main()
{
  void * response;
  pthread_t square_root_thread;
  pthread_create(&square_root_thread, NULL , compute_square_root, NULL);
  printf("Wait for another thread to compute square roots from 0 to 99\n");
  pthread_join(square_root_thread, &response);
  double * results = (double *) response;
  printf("Completed..\n");
  for ( int i = 0; i < 100; ++i ) {
    printf(" %d ---> %g\n", i, results[i]);
  }
  return 0;
}
