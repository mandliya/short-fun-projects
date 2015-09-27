#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
long shared_data;   // could be more complicated then just an int.

void * increment( void * arg )
{
  long i = 0;
  for ( i = 0; i < 1024 * 1024 * 128; ++i ) {
    pthread_mutex_lock(&lock);
    ++shared_data;
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

int main()
{
  pthread_t thread_id;
  void * exit_status;
  int i;

  //initialize the mutex
  pthread_mutex_init(&lock, NULL);
  //create the thread
  pthread_create(&thread_id, NULL, increment, NULL);

  // Lets access shared data
  for ( i = 0; i < 10; ++i ) {
    //sleep(1);
    pthread_mutex_lock(&lock);
    printf("Shared integer's value is %ld\n", shared_data);
    pthread_mutex_unlock(&lock);
  }
  pthread_join(thread_id, &exit_status);
  pthread_mutex_destroy(&lock);
  return 0;
}
