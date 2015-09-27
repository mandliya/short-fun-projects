#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void * hello_world( void * arg )
{
  long thread_id = (long)arg;
  int i;
  for (i = 0; i < 2; ++i) {
    printf("Hello World from thread %ld\n", thread_id);
  }
  return NULL;
}

int main()
{
  pthread_t thread_list[NUM_THREADS];
  void * exit_status;
  for( long i = 0; i < NUM_THREADS; ++i ) {
    pthread_create(&thread_list[i], NULL , hello_world, (void *)i);
  }
  for( int i = 0; i < 5; ++i ) {
    pthread_join(thread_list[i], &exit_status);
  }
  return 0;
}
